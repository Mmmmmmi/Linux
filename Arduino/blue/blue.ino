//void setup()
//{
//  Serial.begin(19200);
//}
//void loop()
//{
//  while (Serial.available()) {
//    char c = Serial.read();
//    
//    if (c) {
//      Serial.println(c);
//      Serial.println("Hello I am amarino");
//    }
//  }
//}



//int num = 0;
// 
//void setup()
//{
// Serial.begin(9600);
//}
// 
//void loop()
//{
//  while(Serial.available())
//   {
//     char c=Serial.read();
//          num++;
//          Serial.print("Hello:num=");
//          Serial.println(num);
//          Serial.println(c);
//   }
//}




#include <SoftwareSerial.h>

String item;

String currentInfo="";

SoftwareSerial mySerial(4, 5);   //根据实际模块上的跳线，选择对应端口

#define my_Serial  mySerial   //声明软串口

void setup()

{
  item = "";

  my_Serial.begin(9600);

  Serial.begin(9600);

}

void loop()

{
  if (my_Serial.available() > 0) {

   currentInfo = my_Serial.readStringUntil('\n');  //接收手机发送的数据

    Serial.println(currentInfo);          //手机发送过来的数据串口返回
  }
  if (Serial.available() > 0) {

    item = Serial.readString();       //接收PC端串口数据

    my_Serial.println(item);          //串口数据发给手机

    Serial.println(item);
  }
}












