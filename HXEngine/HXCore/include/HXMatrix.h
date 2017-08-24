#pragma once
#include "HXCommon.h"

namespace HX3D
{
	struct HXMatrix44
	{
		static HXMatrix44 IDENTITY;
		float m[4][4];

		HXMatrix44()
		{
			memset(m, 0, sizeof(float) * 16);
		}

		HXMatrix44(const HXMatrix44& right)
		{
			m[0][0] = right.m[0][0]; m[0][1] = right.m[0][1]; m[0][2] = right.m[0][2]; m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0]; m[1][1] = right.m[1][1]; m[1][2] = right.m[1][2]; m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0]; m[2][1] = right.m[2][1]; m[2][2] = right.m[2][2]; m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0]; m[3][1] = right.m[3][1]; m[3][2] = right.m[3][2]; m[3][3] = right.m[3][3];
		}

		HXMatrix44(float m0_0, float m0_1, float m0_2, float m0_3,
			float m1_0, float m1_1, float m1_2, float m1_3,
			float m2_0, float m2_1, float m2_2, float m2_3,
			float m3_0, float m3_1, float m3_2, float m3_3)
		{
			m[0][0] = m0_0; m[0][1] = m0_1; m[0][2] = m0_2; m[0][3] = m0_3;
			m[1][0] = m1_0; m[1][1] = m1_1; m[1][2] = m1_2; m[1][3] = m1_3;
			m[2][0] = m2_0; m[2][1] = m2_1; m[2][2] = m2_2; m[2][3] = m2_3;
			m[3][0] = m3_0; m[3][1] = m3_1; m[3][2] = m3_2; m[3][3] = m3_3;
		}

		// ת�þ���
		inline HXMatrix44 Transpose() const
		{
			HXMatrix44 temp;	//�������ָ��������⣬��������������ָ����ָ������ҡ��˴�����ָ��ֱ�ӿ�����û��ϵ
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp.m[i][j] = m[j][i];
				}
			}
			return temp;
		}

		inline HXMatrix44 operator+(const HXMatrix44& right) const
		{
			return HXMatrix44(m[0][0] + right.m[0][0], m[0][1] + right.m[0][1], m[0][2] + right.m[0][2], m[0][3] + right.m[0][3],
				m[1][0] + right.m[1][0], m[1][1] + right.m[1][1], m[1][2] + right.m[1][2], m[1][3] + right.m[1][3],
				m[2][0] + right.m[2][0], m[2][1] + right.m[2][1], m[2][2] + right.m[2][2], m[2][3] + right.m[2][3],
				m[3][0] + right.m[3][0], m[3][1] + right.m[3][1], m[3][2] + right.m[3][2], m[3][3] + right.m[3][3]);
		}

		inline HXMatrix44 operator-(const HXMatrix44& right)
		{
			return HXMatrix44(m[0][0] - right.m[0][0], m[0][1] - right.m[0][1], m[0][2] - right.m[0][2], m[0][3] - right.m[0][3],
				m[1][0] - right.m[1][0], m[1][1] - right.m[1][1], m[1][2] - right.m[1][2], m[1][3] - right.m[1][3],
				m[2][0] - right.m[2][0], m[2][1] - right.m[2][1], m[2][2] - right.m[2][2], m[2][3] - right.m[2][3],
				m[3][0] - right.m[3][0], m[3][1] - right.m[3][1], m[3][2] - right.m[3][2], m[3][3] - right.m[3][3]);
		}

		inline HXMatrix44 operator*(float factor) const
		{
			return HXMatrix44(m[0][0] * factor, m[0][1] * factor, m[0][2] * factor, m[0][3] * factor,
				m[1][0] * factor, m[1][1] * factor, m[1][2] * factor, m[1][3] * factor,
				m[2][0] * factor, m[2][1] * factor, m[2][2] * factor, m[2][3] * factor,
				m[3][0] * factor, m[3][1] * factor, m[3][2] * factor, m[3][3] * factor);
		}

		inline HXMatrix44 operator*(const HXMatrix44& right) const
		{
			HXMatrix44 temp;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						temp.m[i][j] += m[i][k] * right.m[k][j];
					}
				}
			}
			return temp;
		}

		inline HXMatrix44& operator=(const HXMatrix44& right)
		{
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[1][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];

			return *this;
		}

		inline bool operator==(const HXMatrix44& right) const
		{
			if (   m[0][0] != right.m[0][0] || m[0][1] != right.m[0][1] || m[0][2] != right.m[0][2] || m[0][3] != right.m[0][3]
				|| m[1][0] != right.m[1][0] || m[1][1] != right.m[1][1] || m[1][2] != right.m[1][2] || m[1][3] != right.m[1][3]
				|| m[2][0] != right.m[2][0] || m[2][1] != right.m[2][1] || m[2][2] != right.m[2][2] || m[2][3] != right.m[2][3]
				|| m[3][0] != right.m[3][0] || m[3][1] != right.m[3][1] || m[3][2] != right.m[3][2] || m[3][3] != right.m[3][3])
			{
				return false;
			}
			return true;
		}

		
	};
}
