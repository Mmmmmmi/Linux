#define PIN A0
#include <Wire.h>
#include <LM75.h>
#include "U8glib.h"

#include "math.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);//The definition OLED connection
float tempOLED, humiOLED, lightnessOLED;

#define INTERVAL_OLED 1000


LM75 sensor(LM75_ADDRESS | 0b000);


unsigned long time0;
unsigned long time_cache0;
bool sta = false, sta_cache = true;
unsigned long getTime0() {
  //返回   从按下的时间开始-------到松手的时间
  sta_cache = sta;
  sta = digitalRead(PIN);
  //   Serial.print("sta = ");
  // Serial.print(sta);
  //     Serial.print("sta_cache = ");
  // Serial.print(sta_cache);
  //   Serial.println();
  delayMicroseconds(200);
  if (sta == HIGH && sta_cache == LOW) {
    time_cache0 = time0;
    time0 = millis();
    //     Serial.print("本次有效");
    return (time0 - time_cache0);
  }
  else {
    //     Serial.print("本次无效");
    //   Serial.println();
    return 0;
  }
}

#define time1_MAX 200
#define time1_MIN 50  //过快的波

unsigned long time1;
unsigned long time1_cache;
boolean time1_sta_error = false;
unsigned long getTime1(unsigned long _t) {
  time1_cache = _t;
  if (time1_cache) {  //有数据时才执行滤波
    if (time1_cache < time1_MAX) {   //滤最小阈值
      if (time1_cache < time1_MIN) { //若有过快的波，开启标志位
        //       Serial.println("make");
        time1_sta_error = true;
      }
      return 0;
    }
    else {
      //      Serial.print(".");
      if (time1_sta_error) {  //如果被标志 则本次波形无效
        //        Serial.println("make done");
        time1_sta_error = false;
        return 0;
      }
      return time1_cache;
    }
  }
  else {
    return 0;
  }
}


#define pulse_MIN 40          //t < 1500ms
#define pulse_MAX 150         //t > 400ms
#define pulse_UPDATA  3
int pulse_num = 0;
unsigned long pulse_vol = 0;
unsigned long pulse_cache = 0;
unsigned long pulse(unsigned long _t) {       //_t 表示按压时间
  if (!_t)
    return 0;

  uint32_t  _pulse_vol = 60000 / _t;

  if ((_pulse_vol > pulse_MIN) && (_pulse_vol < pulse_MAX)) {
    pulse_vol += _pulse_vol;
    pulse_num++;
    if (pulse_num > (pulse_UPDATA - 1)) {
      uint32_t _pulse = pulse_vol / pulse_UPDATA;
      pulse_num = 0;
      pulse_vol = 0;
      pulse_cache = _pulse;
      return _pulse;
    }
    else {
      return 0;
    }
  }
  else {
    pulse_num = 0;
    pulse_vol = 0;
    return 0;
  }
}



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:

  pinMode(A0, INPUT);
  Serial.begin(9600);
  //初始化I2C
  Wire.begin();

}




int temperature = 0, heartrate = 0;     //温度  心率
int timeflag = 0;
int nowtime = 0;
////获取传感器数据
void getSensorData()
{


  //时间控制      5秒测一次
  timeflag = millis() - nowtime;  
  if (timeflag > 5000 && timeflag < 6000) {
    nowtime = millis();
    temperature = sensor.temp();
    Serial.print("Current temp: ");
    Serial.print(temperature);
    Serial.println(" C");
  }

}


static unsigned char bitmap[] U8G_PROGMEM = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x18,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x1C,0x00,0x00,0x00,0x00,
0x00,0xF8,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0xC8,0x01,0x76,0x00,0x00,0x00,0x00,
0x00,0x88,0x03,0x63,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0xE3,0x00,0x00,0x00,0x00,
0x00,0x0C,0xFE,0xC1,0x00,0x00,0x00,0x00,0x00,0x0C,0x06,0xC1,0x00,0x00,0x00,0x00,
0x00,0x07,0x00,0x80,0x03,0x00,0x00,0x00,0x80,0xF3,0x03,0x8F,0x07,0x00,0x00,0x00,
0xC0,0xF9,0xFF,0x7F,0x06,0x00,0x00,0x00,0xC0,0x1D,0xFE,0xFD,0x0C,0x00,0x00,0x00,
0xE0,0x07,0x00,0xC0,0x1F,0x00,0x00,0x00,0xE0,0x03,0x00,0x80,0x3F,0x00,0x00,0x00,
0xF0,0x01,0x00,0x00,0x3F,0x00,0x00,0x00,0xF0,0x01,0x00,0x00,0x3E,0x00,0x00,0x00,
0xF8,0x00,0x68,0x00,0x7C,0x00,0x00,0x00,0xF8,0x00,0x6C,0x00,0x7D,0x00,0x00,0x00,
0x7C,0x00,0x6C,0x00,0x7D,0x00,0x00,0x00,0x7C,0x00,0x08,0x00,0xDD,0x00,0x00,0x00,
0x7C,0x00,0x00,0x00,0xDE,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0xCE,0x00,0x00,0x00,
0xE8,0x00,0x00,0x00,0xCE,0x00,0x00,0x00,0xD8,0x00,0x00,0x00,0xC6,0x00,0x00,0x00,
0xD8,0x01,0x20,0x00,0xC7,0x00,0x00,0x00,0xF8,0x0F,0xFF,0xC3,0xE3,0x00,0x00,0x00,
0xF0,0xFF,0xFF,0xFF,0x63,0x00,0x00,0x00,0xC0,0xF9,0x03,0x7E,0x30,0x00,0x00,0x00,
0x80,0x0F,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x3E,0x03,0x0C,0x0E,0x00,0x00,0x00,
0x00,0xF8,0x00,0xCC,0x07,0x00,0x00,0x00,0x00,0xF0,0x37,0xFC,0x00,0x00,0x00,0x00,
0x00,0xB8,0x9F,0xFF,0x00,0x00,0x00,0x00,0x00,0x3C,0xFC,0xC3,0x01,0x00,0x5F,0x00,
0x00,0x1E,0xF0,0x80,0x01,0xC0,0xFF,0x01,0x00,0x1B,0x00,0x80,0x03,0xF8,0xFF,0x03,
0x80,0x1B,0x00,0xB4,0x03,0xFE,0xBF,0x07,0x80,0x0D,0x00,0x36,0x03,0x87,0x3F,0x0E,
0xC0,0x0D,0x00,0x36,0xC7,0x07,0x7F,0x0C,0xC0,0x04,0x00,0x73,0xE6,0x0F,0x7F,0x0C,
0xC0,0x07,0x00,0x73,0xF6,0x0F,0x7F,0x0C,0x80,0x07,0x00,0x73,0xDE,0x1F,0x7F,0x0C,
0x00,0x03,0x80,0x33,0x9C,0x1F,0x7F,0x0C,0x00,0x03,0x80,0x31,0x8C,0x3F,0x7F,0x0C,
0x00,0x03,0x80,0x33,0x8C,0x3F,0x7E,0x0E,0x80,0x03,0x00,0x1E,0x8C,0x3F,0x7E,0x06,
0x80,0x03,0x00,0x00,0x8C,0x3F,0x7E,0x06,0x00,0x03,0x00,0x00,0xCC,0x3F,0x7E,0x06,
0x00,0x03,0x00,0x00,0xCC,0x3F,0x7E,0x07,0x00,0x07,0x00,0x00,0xCC,0x3F,0x7E,0x03,
0x00,0x06,0x00,0x00,0x86,0x3F,0xFE,0x01,0x00,0x1C,0x00,0x00,0xC7,0x3F,0xFE,0x01,
0x00,0x38,0x00,0x80,0xC3,0x1F,0xFE,0x00,0x00,0x70,0x00,0xC0,0xCF,0x3F,0x7E,0x00,
0x00,0x3E,0x78,0xE0,0xFF,0x1F,0x3F,0x00,0x00,0x1E,0x7C,0xF8,0xF0,0xCF,0x0F,0x00,
0x00,0xFE,0x6F,0x18,0xC0,0xFF,0x01,0x00,0x00,0xFC,0x73,0x18,0x00,0x1C,0x00,0x00,
0x00,0x10,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};










//LED输出
void draw(void)
{
  int x, y, time;
  //================Microduino====================//
  u8g.setFont(u8g_font_fixed_v0r);
  u8g.drawStr(0, 10, "test");
  u8g.drawLine(0, 10, 60, 10);
  u8g.drawLine(0, 0, 128, 0);
  u8g.drawLine(0, 63, 128, 63);
  u8g.drawLine(0, 63, 128, 63);
//  u8g.drawStr(0, 20, "LIG:");
//  u8g.setPrintPos(25, 20);//换行显示须再定义
//  u8g.drawStr(47, 20, "LUX");
  u8g.drawStr(0, 30, "TEM:");
  u8g.setPrintPos(25, 30);//换行显示须再定义
  u8g.print(temperature, DEC);
  u8g.drawStr(47, 30, "CEL");
  u8g.drawLine(0, 63, 128, 63);
  //u8g.drawStr(0, 40, "HUM:");
  u8g.setPrintPos(25, 40);//换行显示须再定义
  u8g.drawStr(0, 50, "heat:");
  u8g.setPrintPos(35, 50);//换行显示须再定义
  u8g.print(heartrate, DEC);
  u8g.drawStr(47, 50, "/min");
  //================ Graph===================//


  //================Pointer table====================//
//  u8g.drawRFrame(68, 2, 60, 60, 18); //(长方形虚（x,y,long,wide,顶角弯曲程度）)
//  u8g.drawLine(98, 2, 98, 6);//12点
  u8g.drawXBMP(68, 2, 120, 64, bitmap);
//  u8g.drawLine(124, 30, 128, 30); //3点
//  u8g.drawLine(98, 57, 98, 61); //6点
//  u8g.drawLine(68, 30, 72, 30); //9点
//  u8g.drawLine(98, 30, 98, 30);
//  time = millis() / 1000;
//  //================Seconds====================//
//  x = 99 + 16 * sin(3.14 * 6 * time / 180);
//  y = 30 - 16 * cos(3.14 * 6 * time / 180);
//  u8g.drawLine(99, 30, x, y);
}



void loop() {
  // print out the value you read:
  //    Serial.print("t0:");
  // Serial.print(digitalRead(A0) * 2000);
  // Serial.println();


  long presstime = getTime0();   //按压时间
  long islegal = getTime1(presstime); //检测有效性    有效返回按压时间 无效返回0
  long retpulse = pulse(islegal);    //心率

  if (presstime) {
    if (islegal) {
      if (retpulse) {
      heartrate = retpulse;
      Serial.print("心率值：");
      Serial.println(heartrate);
      }
    }
  }

  //
  getSensorData();


  //LED屏
  u8g.firstPage();
  do {
    draw();
  }
  while (u8g.nextPage());


  //delay(1000);        // delay in between reads for stability
}
