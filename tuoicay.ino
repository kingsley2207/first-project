#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer webServer(80);

char* ssid = "536 Au Co";
char* pass = "xxxxxxxx";

//=========Biến chứa mã HTLM Website==//
String mainPage ={
"<!DOCTYPE html>"
"<html>"
"<head>"
"<title>Trang Chủ</title>"
"<meta charset='utf-8'>"
"<meta name = 'viewport' content = 'width=device-width, initial-scale=1.0'>"
"<style>"

".header{ width: 100%;"
        "display: flex;"
        "background-image: linear-gradient(15deg,#133eaa  0%, #4cc1f7 90%);"
    "}"
    ".header ul{"
        "text-align:center;"
    "}"
    ".header ul li{"
    "list-style: none;"
    "display: inline;"
    "padding: 10px 10px;"
    "}"
    ".header ul li a{"
    "display:contents;"
    "text-decoration: none;"
    "text-transform: uppercase;"
    "color: #fff; "
    "font-size: 20px;"
    "font-family: 'Times New Roman', Times, serif;"
    "letter-spacing: 1px;"
    "font-weight: 600;"
    "padding: 20px;"
    "}"
    "img{width: 98%;}"
"</style>"
"</head>"
"<body>"
    "<div class='header'> "
        "<ul>"
            "<li>"
                "<a href='./' title='Trang Chủ'>Trang Chủ</a>"
            "</li>"
            "<li>"
                "<a href='./webctrl' title='Giới Thiệu'>Giới Thiệu</a>"
            "</li>"
            "<li>"
                "<a href='./contact' title='Liên Hệ'>Liên Hệ</a>"
            "</li>"
            "<li>"
                "<a href='./faq' title='FAQ'>FAQ</a>"
            "</li>"
        "</ul>"
    "</div>"
    "<div>"
        "<div>"
            "<img src='https://drive.google.com/uc?id=1zR4L8VciIHMwO0Aa8QC00xJweYFZIdF5' >"
        "</div>"
        "<div>"
            "<img src='https://drive.google.com/uc?id=1c1M8WvKNSG5kKq4dXIu2Bvexx-QMn19J'>"
        "</div>"
        "<div>"
            "<img src='https://drive.google.com/uc?id=1QVGZJsUXkyh_M65dBgAbtfGwS9MLYpTX'>"
        "</div>"
        "<div>"
            "<img src='https://drive.google.com/uc?id=1jCLZyiUL5mzemDatOK1GXaKi1tsgRXzw'>"
        "</div>"
    "</div>"
    "<div>"
        "<img src='https://drive.google.com/uc?id=1aJW4Tq2_63t1DYax7mSQy_FoMlXiSHix' style='width: 100%;'>        "
    "</div>"
"</body>"
"</html>"
};

String webPage ={
"<!DOCTYPE html>"
"<html>"
"<head>"
    "<title>Giới thiệu</title>"
    "<meta charset='utf-8'>"
    "<style>"
    ".header{ width: 100%;"
        "display: flex;"
        "background-image: linear-gradient(15deg,#133eaa  0%, #4cc1f7 90%);"
    "}"
    ".header ul{"
        "text-align:center;"
    "}"
    ".header ul li{"
    "list-style: none;"
    "display: inline;"
    "padding: 10px 10px;"
    "}"
    ".header ul li a{"
    "display:contents;"
    "text-decoration: none;"
    "text-transform: uppercase;"
    "color: #fff; "
    "font-size: 20px;"
    "font-family: 'Times New Roman', Times, serif;"
    "letter-spacing: 1px;"
    "font-weight: 600;"
    "padding: 20px;"
    "}"
    "table, th, td "
                "{   padding: 2px;"
                    "border: 1px solid black;"
                    "border-collapse: collapse;"
                    "margin-bottom: 130px; "
                "}"
    ".bt_on{width: 70px;height: 35px;font-size: 15px;background-color:#00ff01;border-radius: 10px;}"
    ".bt_off{width: 70px;height: 35px;font-size: 15px;background-color:#f60;border-radius: 10px;}"
    ""
    ".bt_on:hover{background-color: #fffb05;}  /*nút có màu khi di chuột qua*/"
    ".bt_off:hover{background-color: #f52003;}"
    "</style>"
"</head>"
"<body>"
    "<div class='header'> "
        "<ul>"
            "<li>"
                "<a href='./' title='Trang Chủ'>Trang Chủ</a>"
            "</li>"
            "<li>"
                "<a href='./webctrl' title='Giới Thiệu'>Giới Thiệu</a>"
            "</li>"
            "<li>"
                "<a href='./contact' title='Liên Hệ'>Liên Hệ</a>"
            "</li>"
            "<li>"
                "<a href='./faq' title='FAQ'>FAQ</a>"
            "</li>"
        "</ul>"
    "</div>"
    "<h3 style='margin-left: 20px;'>"
        "<span style='margin-left:2px; font-size:1.0rem;'>Thời gian: </span>"
        "<span id='time' style='margin-left:2px; font-size:1.0rem;'></span>"
        "<br>"
        "<span style='margin-left:2px; font-size:1.0rem;'>Ngày: </span>"
        "<span id='date' style='margin-left:2px; font-size:1.0rem;'></span>"
      "</h3>"
      "<script>"
        "var myVar = setInterval(Time_Date, 1000);"
        "function Time_Date() {"
          "var t = new Date();"
          "document.getElementById('time').innerHTML = t.toLocaleTimeString();"
          "var d = new Date();"
          "const dayNames = ['Chủ Nhật','Thứ hai','Thứ ba','Thứ tư','Thứ năm','Thứ sáu','Thứ bảy'];"
          "const monthNames = ['1','2','3','4','5','6','7','8','9','10','11','12'];"
          "document.getElementById('date').innerHTML = dayNames[d.getDay()] + ', ' + d.getDate() + '-' + monthNames[d.getMonth()] + '-' + d.getFullYear();"
        "}"
        "</script>"

"    <table align='center'>"
        "<h1 align = 'center'> BẢNG ĐIỀU KHIỂN </h1>"
        "<tr style= 'text-align: center; padding: 1px; text-transform: uppercase; background: orange'>"
            "<th>Vị trí</th>"
            "<th>Thiết bị</th>"
            "<th>Thông số</th>"
            "<th>Trạng thái</th>"
            "<th colspan='2'> THAO TÁC</th>"
        "</tr>"
        "<tr style= 'text-align: center'>"
            
            "<td>Phòng khách</td>"
            "<td><p>Đèn</p></td>"
            "<td></td>"
            "<td><p id='trangthaiD1'>  </p></td>"
            "<td> <a href='/onD1'><input type='button' class='bt_on' onclick='getdata('onD1')' value = 'ON'> </a> </td>"
"            <td> <a href='/offD1'><input type='button' class='bt_off' onclick='getdata('offD1')' value = 'OFF'> </a> </td>"
"        </tr>"
"        <tr style= 'text-align: center'>"
"          <td>Phòng ngủ</td>"
"          <td><p>Quạt</p></td>"
"          <td>   </td>"
"          <td><p id='trangthaiD2'></td>"
"          <td> <a href='/onD2'><input type='button' class='bt_on' onclick='getdata('onD2')' value = 'ON'> </a> </td>"
"          <td> <a href='/offD2'><input type='button' class='bt_off' onclick='getdata('offD2')' value = 'OFF'> </a> </td>"
"      </tr>"
"        "
"        <tr style= 'text-align: center'>"
"            <td>Sân vườn</td>"
"            <td><p>Máy bơm</p></td>"
"            <td>   </td>"
"            <td>    </td>"
"          <td> <a href='/onD6'><input type='button' class='bt_on' onclick='getdata('onD3')' value = 'ON'> </a> </td>"
"          <td> <a href='/offD6'><input type='button' class='bt_off' onclick='getdata('offD3')' value = 'OFF'> </a> </td>"
"        </tr>"
"        <tr style= 'text-align: center'>"
"            <td rowspan='2'>Phòng bếp</td>"
"            <td> <p>Nhiệt độ</p></td>"
"            <td rowspan='2'></td>"
"            <td rowspan='2'></td>"
"            <td rowspan='2'></td>"
"            <td rowspan='2'></td>"
"        </tr>"
"        <tr style= 'text-align: center'> "
"            <td> <p class='gas'> Khí gas: </p></td>"
"          </tr>"
"        </table>"
"        <div>"
"            <img src='https://drive.google.com/uc?id=1aJW4Tq2_63t1DYax7mSQy_FoMlXiSHix' style='width: 100%;'>        "
"        </div>"
        "<script>"
  //--Tạo đối tượng yêu cầu
  "function create_obj(){"
  "td = navigator.appName;"
  "if(td == 'Microsoft Internet Explorer'){"
  "obj = new ActiveXObject('Microsoft.XMLHTTP');"
  "}else{"
  "obj = new XMLHttpRequest();"
  "}"
  "return obj;"
  "}"
  "var xhttp = create_obj();"
  //-----------Thiết lập dữ liệu và gửi request-------
  "function getdata(url){"
  "xhttp.open('GET', '/' + url, true);"
  "xhttp.onreadystatechange = process;"//nhận reponse 
  "xhttp.send();"
  "}"
  //-----------Kiểm tra response--------------------
  "function process()"
  "{"
  "if(xhttp.readyState == 4 && xhttp.status == 200){"
  //------Update data sử dụng javascript----------
  "ketqua = xhttp.responseText;"
  "document.getElementById('reponsetext').innerHTML=ketqua; "    
  "}"
  "}"
  //------------Kiểm tra trạng thái chân D1 D2------
  "function getstatusD1D2(){"
  "xhttp.open('GET','getstatusD1D2',true);"
  "xhttp.onreadystatechange = process_json;"
  "xhttp.send();"
  "}"
  //-----------Kiểm tra response---------------------------
  "function process_json(){"
  "if(xhttp.readyState == 4 && xhttp.status == 200){"
  //------Update data sử dụng javascript-------------------
  "var trangthaiD1D2_JSON = xhttp.responseText;"
  "var Obj = JSON.parse(trangthaiD1D2_JSON);"
  "document.getElementById('trangthaiD1').innerHTML = Obj.D1;"
  "document.getElementById('trangthaiD2').innerHTML = Obj.D2;"
//  "document.getElementById('trangthaiD3').innerHTML = Obj.D3;"
//  "document.getElementById('trangthaiD4').innerHTML = Obj.D4;"
//  "document.getElementById('trangthaiD5').innerHTML = Obj.D5;"
  "}"
  "}"
  //---Ham update du lieu tu dong---
  "setInterval(function() {"
  "getstatusD1D2();"
  "}, 1000);"
  "</script>"

"        </body>"
"        </html>"
};

String contactPage={
"<!DOCTYPE html>"
"<html>"
"<head>"
"    <title>Liên Hệ</title>"
"    <meta charset='utf-8'>"
"<style>"

    ".header{ width: 100%;"
        "display: flex;"
        "background-image: linear-gradient(15deg,#133eaa  0%, #4cc1f7 90%);"
    "}"
    ".header ul{"
        "text-align:center;"
    "}"
    ".header ul li{"
    "list-style: none;"
    "display: inline;"
    "padding: 10px 10px;"
    "}"
    ".header ul li a{"
    "display:contents;"
    "text-decoration: none;"
    "text-transform: uppercase;"
    "color: #fff; "
    "font-size: 20px;"
    "font-family: 'Times New Roman', Times, serif;"
    "letter-spacing: 1px;"
    "font-weight: 600;"
    "padding: 20px;"
    "}"
    "img{width: 98%;}"
"</style>"
"</head>"
"<body>"
    "<div class='header'> "
        "<ul>"
            "<li>"
                "<a href='./' title='Trang Chủ'>Trang Chủ</a>"
            "</li>"
            "<li>"
                "<a href='./webctrl' title='Giới Thiệu'>Giới Thiệu</a>"
            "</li>"
            "<li>"
                "<a href='./contact' title='Liên Hệ'>Liên Hệ</a>"
            "</li>"
            "<li>"
                "<a href='./faq' title='FAQ'>FAQ</a>"
            "</li>"
        "</ul>"
    "</div>"
    "<div id='main-content' align = 'center'>"
        "<div>"
            "<iframe src='https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3919.4945995049425!2d106.65843061411644!3d10.773379562197537!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x31752ec3c161a3fb%3A0xef77cd47a1cc691e!2zVHLGsOG7nW5nIMSQ4bqhaSBo4buNYyBCw6FjaCBraG9hIC0gxJDhuqFpIGjhu41jIFF14buRYyBnaWEgVFAuSENN!5e0!3m2!1svi!2s!4v1615288067012!5m2!1svi!2s' width='600' height='450' style='border:0;' loading='lazy'></iframe>"
        "</div>"
    "</div>"
    "<p>Mọi thắc mắc quý khách hàng vui lòng liên hệ số điện thoại 0976540359. </p>"
"</body>"
"</html>"
  };
  
String faqPage={
"<!DOCTYPE html>"
"<html>"
"<head>"
"    <title>Câu Hỏi Thường Gặp</title>"
"    <meta charset='utf-8'>"
    "<style>"
    ".header{ width: 100%;"
        "display: flex;"
        "background-image: linear-gradient(15deg,#133eaa  0%, #4cc1f7 90%);"
    "}"
    ".header ul{"
        "text-align:center;"
    "}"
    ".header ul li{"
    "list-style: none;"
    "display: inline;"
    "padding: 10px 10px;"
    "}"
    ".header ul li a{"
    "display:contents;"
    "text-decoration: none;"
    "text-transform: uppercase;"
    "color: #fff; "
    "font-size: 20px;"
    "font-family: 'Times New Roman', Times, serif;"
    "letter-spacing: 1px;"
    "font-weight: 600;"
    "padding: 20px;"
    "}"

".item-wrapper {"
"    margin-bottom: 20px;"
"    border: 1px solid #ddd;"
"    border-radius: 4px;"
"}"
".question {"
"    background-color: #f5f5f5;"
"    padding: 10px 15px;"
"}"
".answer {"
"    padding: 15px;"
"    display: none;"
"}"
".toggle-display {"
"    border: 1px solid #aaa;"
"    padding: 1px 5px;"
"    margin-right: 5px;"
"    cursor: pointer;"
"}"
    "</style>"

"</head>"

"<body>"
    "<div class='header'> "
        "<ul>"
            "<li>"
                "<a href='./' title='Trang Chủ'>Trang Chủ</a>"
            "</li>"
            "<li>"
                "<a href='./webctrl' title='Giới Thiệu'>Giới Thiệu</a>"
            "</li>"
            "<li>"
                "<a href='./contact' title='Liên Hệ'>Liên Hệ</a>"
            "</li>"
            "<li>"
                "<a href='./faq' title='FAQ'>FAQ</a>"
            "</li>"
        "</ul>"
    "</div>"


    "<div>"
    "<div align='center'>"
    "     <img src='https://drive.google.com/uc?id=1jgXMsaVPOHt6jJ3eTDJYIUo93ds4vPn8'>"
    "</div>"
"        <div class='item-wrapper'>"
"            <div class='question'>"
"                <strong class='toggle-display'>+</strong> Nếu như có câu hỏi hoặc không hài lòng về dịch vụ chúng tôi có thể khiếu nại với bộ phần nào?"
"            </div>"
"            <div class='answer'>"
"                Nếu quý khách không hài lòng về dịch vụ cung cấp bởi công ty chúng tôi quý khách có thể liên hệ bộ phần Chăm Sóc Khách Hàng chúng tôi luôn sẵn lòng hỗ trợ mọi thắc mắc hoặc phàn nàn về dịch vụ."
"            </div>"
"        </div>"
"        <div class='item-wrapper'>"
"            <div class='question'>"
"                <strong class='toggle-display'>+</strong> Thời gian nhận được trả lời cho thắc mắc hoặc khiếu nại về dịch vụ là bao lâu?"
"            </div>"
"            <div class='answer'>"
"                Sau khi tiếp nhận thắc mắc hoặc khiếu nại của quý khách chúng tôi sẽ thực hiện việc xử lý yêu cầu trong vòng tối đa 24h."
"            </div>"
"        </div>"
"        <div class='item-wrapper'>"
"            <div class='question'>"
"                <strong class='toggle-display'>+</strong> Khách hàng có nhận được hoá đơn khi mua dịch vụ của chúng tôi?"
"            </div>"
"            <div class='answer'>"
"                Có, tất cả các khách hàng đều nhận được hoá đơn giá trị gia tăng cho các dịch vụ cung cấp bới công ty chúng tôi."
"            </div>"
"        </div>"
"        <div class='item-wrapper'>"
"            <div class='answer'>"
"                <strong class='toggle-display'>+</strong> Sau khi đặt mua dịch vụ thì quy trình thanh toán sẽ như thế nào?"
"            </div>"
"            <div class='answer'>"
"                Sau khi quý khách hàng đặt mua dịch vụ qua điện thoại, email hoặc thông qua bất kỳ một hình thức giao dịch hợp lệ nào khác thì quý khách hàng có thể thanh toán qua dịch vụ Internet Banking, thẻ ATM hoặc thanh toán tại văn phòng chúng tôi."
"            </div>"
"        </div>"
"    </div>"

  "<div align='center'>"
  "     <img src='https://drive.google.com/uc?id=1aJW4Tq2_63t1DYax7mSQy_FoMlXiSHix' style='width: 100%;'>        "
  "</div>"
  
"<script>"
"var questions = document.getElementsByClassName('question');"

"for (var j = 0; j < questions.length; j++) {"
    "var question = questions[j];"

    "question.onclick = function () {"
        "var answer = this.nextElementSibling;" // Dùng 'this' => OK (y)(y)(y)
        "console.log(answer);"

        "var display = answer.style.display;"
        "answer.style.display = display == 'block' ? 'none' : 'block';"

        "var iconText = this.getElementsByClassName('toggle-display')[0].innerText;"
        "this.getElementsByClassName('toggle-display')[0].innerText = (iconText == '+') ? '-' : '+';"
    "}"
    " }"
      "</script>"
  };
void Trangchu(){
  webServer.send(200,"text/html",mainPage);
} 
void webctrl(){
  webServer.send(200,"text/html",webPage);
}
void contact(){
  webServer.send(200,"text/html",contactPage);
}
void faq(){
  webServer.send(200,"text/html",faqPage);
}
void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
    Serial.println("Da ket noi, dia chi IP la: ");
  Serial.println(WiFi.localIP());}
 
  webServer.on("/", Trangchu); 
  webServer.on("/webctrl", webctrl);
  webServer.on("/contact", contact);
  webServer.on("/faq", faq);
  
  webServer.on("/onD1",on_D1);
  webServer.on("/offD1",off_D1);
  webServer.on("/onD2",on_D2);
  webServer.on("/offD2",off_D2);
  webServer.on("/getstatusD1D2",get_statusD1D2);
  
//  webServer.on("/onD4",on_D4);
//  webServer.on("/onD5",on_D5);
//  webServer.on("/offD5",off_D5);
//  webServer.on("/onD6",on_D6);
//  webServer.on("/offD6",off_D6);
 
  webServer.begin();
}

void get_statusD1D2(){
  String d1,d2;
  if(digitalRead(D1)==1){
    d1 = "OFF";
  }else{
    d1 = "ON";
  }
  if(digitalRead(D2)==1){
    d2 = "OFF";
  }else{
    d2 = "ON";
  }
  String s = "{\"D1\": \""+ d1 +"\",\"D2\": \""+ d2 +"\"}";
  webServer.send(200,"application/json",s);
}
void loop() {
  webServer.handleClient();
  }
//==========Chương trình con=================//

//
void on_D1(){
  digitalWrite(D1, 0);
  webServer.send(200,"text/html",webPage);
}
void off_D1(){
  digitalWrite(D1, 1);
  webServer.send(200,"text/html",webPage);
}

void on_D2(){
  digitalWrite(D2, 0);
  webServer.send(200,"text/html",webPage);
}
void off_D2(){
  digitalWrite(D2, 1);
  webServer.send(200,"text/html",webPage);
}
//void on_D5(){
//  digitalWrite(D8,0); /* Chân tín hiệu relay */
//  Serial.println("Bat may tuoi cay");
//  String s = dieukhien;
//  webServer.send(200,"text/html",s);
//      int moisture=analogRead(A0);
//      delay(1000);
//      while(moisture>850){
//      delay(1000);
//      moisture=analogRead(A0);
//      Serial.print("Gia tri analog: ");
//      Serial.println(moisture);
//      Serial.println("Dang tuoi cay ");         
//}  
//      digitalWrite(D8, 1);
//      Serial.println(moisture);
//      Serial.println("Da tuoi xong, tat may bom");
//      
//}
//void off_D5(){
//  digitalWrite(D8, 1);
//  Serial.println("Da tuoi"); 
//  String s = dieukhien;
//  webServer.send(200,"text/html",s);  
//}
//void on_D6(){
//  
// 
//  digitalWrite(D8, 1);        
//  String s = dieukhien;
//  webServer.send(200,"text/html",s);
//  for(int i=1;i>0;i++) {
//  int value=digitalRead(D7); delay(200);
//  if (value==1) {Serial.println("Dang tuoi cay "); delay(200);}
//  
//  if (value==0) {Serial.println("Hư máy bơm"); delay(200);}
//  }
//}
//void off_D6(){
//  digitalWrite(D8, 0);
//  String s = dieukhien;
//  webServer.send(200,"text/html",s);
//}
