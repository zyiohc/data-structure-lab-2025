#pragma once
#include "Car.h" // �ڵ��� Ŭ���� ������� ����

// ������ī Ŭ���� (�ڽ� Ŭ����) : �ڵ��� Ŭ������ �ͺ� ��� �߰�
class SportsCar : public Car
{
public:
	bool bTurbo; // �ͺ� ��ġ ON?
	void setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() { // �ͺ��� ON�� �Ǿ� ������ ������ ������
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};