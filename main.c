#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

//265 25 25
int main()
{

   Open(szPort);
   SensorData data1;

   Go(0, 0);

   while (1)
   {
      data1 = Sensor(1);
      printf("%d %d %d %d %d ����:%d ������:%d \n", data1.IRSensor[0], data1.IRSensor[1], data1.IRSensor[2], data1.IRSensor[3], data1.IRSensor[4],data1.TorqueSensor[1],data1.TorqueSensor[0]);


      if ((data1.IRSensor[0] > 265) && (data1.IRSensor[1] > 25) && (data1.IRSensor[2] > 25)) //������ ��������
      {
         if ((data1.IRSensor[4] > 15) && (data1.IRSensor[3] > 15))
         {
            Go(0, 0);
            Close();
            return 0;
         }

         else if (data1.IRSensor[4] > data1.IRSensor[3]) //�������� �����վ �������� ���ƾߵɶ�
         {
            Go(-300, -300);
            Steering(2);
            delay(800);//�������������� ������ ����

            Go(500, 500);
            Steering(1);
            delay(800);//���� �������� ������ ����
         }
         if (data1.IRSensor[4] < data1.IRSensor[3])//���������� �����վ ���������� ���ƾߵɶ�
         {
            Go(-300, -300);
            Steering(2);
            delay(800);

            Go(500, 500);
            Steering(3);
            delay(800);
         }

      }

      else if (data1.IRSensor[0] > 265 && data1.IRSensor[1] > 25) //���������� �缱�� �����ļ� ���������� ����
      {
         Go(-300, -300);
         Steering(2);
         delay(800);

         Go(500, 500);
         Steering(3);
         delay(800);
      }
      else if (data1.IRSensor[1] > 25 && data1.IRSensor[2] > 25) //�������� �缱�� �����ļ� �������� ����
      {
         Go(-300, -300);
         Steering(2);
         delay(800);

         Go(500, 500);
         Steering(1);
         delay(800);

      }

      else if (data1.IRSensor[3] < 25)//������
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
         Go(500, 500); Steering(2);//��� ����
      }
   }



   Close();

   //return 0;
}