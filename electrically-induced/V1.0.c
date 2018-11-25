/*
本源码为电磁小车的源码，除了红外换成电感及电感放大板外其他硬件不变
BY:Tomcat
*/
volatile int left;
volatile int right;
//定义左右电感回读变量
volatile int lspeed;
volatile int rspeed;
//定义左右速度输出变量

void setup(){
  left = analogRead(A0);
  right = analogRead(A1);
  //左右电感回读模拟pwm
  lspeed = 0;
  rspeed = 0;
}

void loop(){
  analogWrite(5,lspeed);
  analogWrite(6,rspeed);
  //左右速度pwm输出

  if (270 <= left && left <= 310) { //电感值范围检测，防止出事
    rspeed = left * 0.5; //右边轮子的速度跟左边电感值的关系

  }
  if (270 <= right && right <= 310) {
    lspeed = right * 0.5;

  }

}