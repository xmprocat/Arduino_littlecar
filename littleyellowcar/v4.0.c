//这个是4个红外的版本，部分2.0版本有的就不再重复注释，部分地方有补充
volatile long CH1;
volatile long CH2;
volatile long CH3;
volatile long CH4;
//这四个是红外
volatile long zhuang;
volatile long dlspeed;
volatile long drspeed;
//左右倒车速度
volatile long qlspeed;
volatile long qrspeed;
//左右前进速度
volatile long lspeed;
volatile long rspeed;
//左右总速度
volatile long gspeed;
//全局速度

void setup(){
  Serial.begin(9600);
  CH1 = 0;
  CH2 = 0;
  CH3 = 0;
  CH4 = 0;
  zhuang = 0;
  dlspeed = 0;
  drspeed = 0;
  qlspeed = 0;
  qrspeed = 0;
  lspeed = 0;
  rspeed = 0;
  gspeed = 0;
  //初始化
}

void loop(){
  CH1 = analogRead(A0);
  CH2 = analogRead(A1);
  CH3 = analogRead(A3);
  CH4 = analogRead(A4);
  zhuang = analogRead(A2);
  //回读模拟输入管脚的信号
  Serial.println(CH1);
  //串口调试

  analogWrite(9,dlspeed);
  analogWrite(10,drspeed);
  //串口输出倒车速度

  analogWrite(5,qlspeed);
  analogWrite(6,qrspeed);
  //串口输出前进速度

  if (lspeed > 0) {
    qlspeed = lspeed;
    dlspeed = 0;

  }
  if (lspeed < 0) {
    qlspeed = 0;
    dlspeed = abs(lspeed);

  }
  if (lspeed == 0) {
    qlspeed = 0;
    dlspeed = 0;

  }

  if (rspeed > 0) {
    qrspeed = rspeed;
    drspeed = 0;

  }
  if (rspeed < 0) {
    qrspeed = 0;
    drspeed = abs(rspeed); //速度取绝对值再赋值给倒车速度

  }
  if (lspeed == 0) {
    qrspeed = 0;
    drspeed = 0;

  }

  if (zhuang < 100) {
    gspeed = 0;

  } else {
    gspeed = 132; //速度不是越快越好，速度太快抖得也厉害，总速度还没慢慢走的来得快

  }

  if (CH2 - CH3 < -25) { //线在2通道上时
    lspeed = 200;
    rspeed = -1;

  }
  if (CH2 - CH3 > 25) { //线在3通道上时
    lspeed = -1;
    rspeed = 200;

  }

 
  if (CH2 - CH3 >= -25 && CH2 - CH3 <= 25) {  // 如果23通道为空
    
    if (CH1 - CH4 < -25) { //线在1通道上时
      lspeed = 80;
      rspeed = -80;

    } else if (CH1 - CH4 > 25) { //线在4通道上时
      lspeed = -80;
      rspeed = 80;
    } else if (CH1 - CH4 >= -25 && CH1 - CH4 <= 25) { // 23通道为空且14为空
      lspeed = gspeed;
      rspeed = gspeed;
    }

  }

}
