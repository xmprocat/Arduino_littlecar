volatile long left;
volatile long right;
volatile long pian;
volatile long zhuang;
volatile long dlspeed;
volatile long drspeed;
volatile long qlspeed;
volatile long qrspeed;
volatile long lspeed;
volatile long rspeed;
volatile long gspeed;
//定义变量
void setup(){
  Serial.begin(9600);
  left = 0;
  right = 0;
  pian = 0;
  zhuang = 0;
  dlspeed = 0;
  drspeed = 0;
  qlspeed = 0;
  qrspeed = 0;
  lspeed = 0;
  rspeed = 0;
  gspeed = 0;
  //初始化变量
}

void loop(){
  left = analogRead(A0);
  right = analogRead(A1);
  zhuang = analogRead(A2);
  //模拟数据输入
  pian = left - right;
  //左右红外寻迹回读变量做差
  Serial.println(pian);
  //串口输出调试数据

  analogWrite(9,dlspeed);
  analogWrite(10,drspeed);
  //模拟输出管脚9、10输出左右马达的倒车pwm值

  analogWrite(5,qlspeed);
  analogWrite(6,qrspeed);
  //模拟输出管脚5、6输出左右马达的倒车pwm值

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
    drspeed = abs(rspeed);

  }
  if (lspeed == 0) {
    qrspeed = 0;
    drspeed = 0;

  }
//对前进后退的总速度变量进行判断并分别赋值给对应的前进后退变量
  if (zhuang < 100) {
    gspeed = 0;

  } else {
    gspeed = 120;

  }
//回读并判断避障模块的数值，装上东西就停车
  if (pian < -250) {
    lspeed = 200;
    rspeed = -30;

  }
//右转
  if (pian > 250) {
    lspeed = -30;
    rspeed = 200;

  }
//左转
  if (pian <= 250 && pian >= -250) {
    lspeed = gspeed;
    rspeed = gspeed;

  }
//直行
}
