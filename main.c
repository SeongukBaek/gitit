#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"
//test
//test2
//265 25 25
//test 3 it's me mario-!
int main()
{

   Open(szPort);
   SensorData data1;

   Go(0, 0);

   while (1)
   {
      data1 = Sensor(1);
      printf("%d %d %d %d %d 왼쪽:%d 오른쪽:%d \n", data1.IRSensor[0], data1.IRSensor[1], data1.IRSensor[2], data1.IRSensor[3], data1.IRSensor[4],data1.TorqueSensor[1],data1.TorqueSensor[0]);


      if ((data1.IRSensor[0] > 265) && (data1.IRSensor[1] > 25) && (data1.IRSensor[2] > 25)) //앞으로 막혔을때
      {
         if ((data1.IRSensor[4] > 15) && (data1.IRSensor[3] > 15))
         {
            Go(0, 0);
            Close();
            return 0;
         }

         else if (data1.IRSensor[4] > data1.IRSensor[3]) //왼쪽으로 공간잇어서 왼쪽으로 돌아야될때
         {
            Go(-300, -300);
            Steering(2);
            delay(800);//바퀴오른쪽으로 돌리고 후진

            Go(500, 500);
            Steering(1);
            delay(800);//바퀴 왼쪽으로 돌리고 전진
         }
         if (data1.IRSensor[4] < data1.IRSensor[3])//오른쪽으로 공간잇어서 오른쪽으로 돌아야될때
         {
            Go(-300, -300);
            Steering(2);
            delay(800);

            Go(500, 500);
            Steering(3);
            delay(800);
         }

      }

      else if (data1.IRSensor[0] > 265 && data1.IRSensor[1] > 25) //오른쪽으로 사선을 마주쳐서 오른쪽으로 돌때
      {
         Go(-300, -300);
         Steering(2);
         delay(800);

         Go(500, 500);
         Steering(3);
         delay(800);
      }
      else if (data1.IRSensor[1] > 25 && data1.IRSensor[2] > 25) //왼쪽으로 사선을 마주쳐서 왼쪽으로 돌때
      {
         Go(-300, -300);
         Steering(2);
         delay(800);

         Go(500, 500);
         Steering(1);
         delay(800);

      }

      else if (data1.IRSensor[3] < 25)//오른쪽
      {
         Go(-300, -300);
         Steering(2);
         delay(800);

         Go(500, 500);
         Steering(3);
         delay(800);
      }

      else
      {
         Go(500, 500); Steering(2);//계속 직진
      }
   }



   Close();

   //return 0;
}