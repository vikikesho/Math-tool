#include "SubFunctions.h"

float RoundFloat(float var)
{
	float value = (int)(var * 100 + .5); //Hàm làm tròn tới chữ số thập phân thứ 2
	return (float)value / 100;//bằng cách nhân số đó cho 100, sau đó cộng 0.5, cast kiểu thành int rồi chia 100.
}

