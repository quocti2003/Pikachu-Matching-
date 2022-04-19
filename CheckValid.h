#pragma once
#include "PlayStandard.h"
#include "my_lib.h"

bool check_I_doc(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int vt_start;
	int vt_end;
	if (x1 == x2)
	{
		/*if (abs(y1 - y2) == 3)
			if (kt[pos1].ch == kt[pos2].ch && kt[pos1].ch != ' ' && kt[pos2].ch != ' ')
				return true;*/


		if (y1 < y2)
		{
			vt_start = x1 / 5 + y1 / 3 * cols;
			vt_end = x2 / 5 + y2 / 3 * cols;
			for (int i = vt_start + cols; i <= vt_end - cols; )
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			/*if (kt[vt_start].ch == kt[vt_end].ch && kt[vt_start].ch != ' ' && kt[vt_end].ch != ' ')*/
			return true;
			/*else
				return false;*/
		}
		else if (y1 > y2)
		{
			vt_start = x2 / 5 + y2 / 3 * cols;
			vt_end = x1 / 5 + y1 / 3 * cols;
			for (int i = vt_start + cols; i <= vt_end - cols; )
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			/*if (kt[vt_start].ch == kt[vt_end].ch && kt[vt_start].ch != ' ' && kt[vt_end].ch != ' ')*/
			return true;
			/*else
				return false;*/
		}
	}
}
bool check_I_ngang(int x1, int y1, int x2, int y2)
{
	int vt_start;
	int vt_end;
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	if (y1 == y2)
	{
		/*if (abs(x1 - x2) == 5)
			if (kt[pos1].ch == kt[pos2].ch && kt[pos1].ch != ' ' && kt[pos2].ch != ' ')
				return true;*/

		if (x1 < x2)
		{
			vt_start = x1 / 5 + y1 / 3 * cols;
			vt_end = x2 / 5 + y2 / 3 * cols;
			for (int i = vt_start + 1; i <= vt_end - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else if (x1 > x2)
		{
			vt_start = x2 / 5 + y2 / 3 * cols;
			vt_end = x1 / 5 + y1 / 3 * cols;
			for (int i = vt_start + 1; i <= vt_end - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}
}
bool check_L1(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int tdgdy = y2;
	int tdgdx = x1;
	int posgd = x1 / 5 + y2 / 3 * cols;
	if (kt[posgd].ch != ' ')
		return false;
	else if (x1 < x2)
	{
		if (y1 < y2)
		{
			for (int i = pos1 + cols; i <= posgd - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}

			for (int i = posgd + 1; i <= pos2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = posgd + cols; i <= pos1 - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}

			for (int i = posgd + 1; i <= pos2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (y1 < y2)
		{
			for (int i = pos1 + cols; i <= posgd - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			for (int i = pos2 + 1; i <= posgd - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = pos2 + 1; i <= posgd - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			for (int i = posgd + cols; i <= pos1 - cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}

}
bool check_L2(int x1, int y1, int x2, int y2)
{
	int tdgdy = y1;
	int tdgdx = x2;
	int posgd = x2 / 5 + y1 / 3 * cols;
	if (kt[posgd].ch != ' ')
		return false;
	if (check_I_doc(x2, y2, tdgdx, tdgdy) == true)
	{
		if (check_I_ngang(x1, y1, tdgdx, tdgdy) == true)
			return true;
	}
	return false;
}
bool check_U_down(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int y1chay = y1 + 3;
	int y2chay = y2 + 3;
	int stt_gd1 = pos1 + cols;
	int stt_gd2 = pos2 + cols;
	/* =======   MẶC ĐỊNH    =======   */

	if (y1 == 3 * lines - 1 && y2 == 3 * lines - 1)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 3 * lines + 2)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 3 * lines + 2)
		return false;

	if (y1 == 3 * lines - 1 || y2 == 3 * lines - 1)
	{
		if (y1 == 3 * lines - 1)
		{
			for (int i = stt_gd2; i <= x2 / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		else if (y2 == 3 * lines - 1)
		{
			for (int i = stt_gd1; i <= x1 / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 += cols;
			y1chay += 3;
			if (y1chay >= 3 * lines + 2)
			{
				/*kt[stt_gd1].ch = ' ';*/
				break;
			}
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 += cols;
			y2chay += 3;
			if (y2chay >= 3 * lines + 2)
			{
				/*kt[stt_gd2].ch = ' ';*/
				break;
			}
		}

		if (y1chay >= 3 * lines + 2 && y2chay >= 3 * lines + 2)
			return true;

		stt_gd1 -= cols;
		stt_gd2 -= cols;
		y1chay -= 3;
		y2chay -= 3;

		if (y1chay < y2 || y2chay < y1) return false;

		if (y1chay == 3 * lines - 1)
		{
			for (int i = pos2 + cols; i <= x2 / 5 + y1chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (y2chay == 3 * lines - 1)
		{
			for (int i = pos1 + cols; i <= x1 / 5 + y2chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		if (x1 <= x2)
		{
			for (int i = stt_gd1 + 1; i <= x2 / 5 + y1chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= stt_gd2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - 1)
					return true;
			}
			return false;
		}

		else if (x1 >= x2)
		{
			for (int i = stt_gd2 + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = x2 / 5 + y1chay / 3 * cols; i <= stt_gd1 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd1 - 1)
					return true;
			}
			return false;
		}
	}
}
bool check_U_up(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int y1chay = y1 - 3;
	int y2chay = y2 - 3;
	int stt_gd1 = pos1 - cols;
	int stt_gd2 = pos2 - cols;
	/* =======   MẶC ĐỊNH    =======   */

	if (y1 == 2 && y2 == 2)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 3 * lines + 2)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 3 * lines + 2)
		return false;

	if (y1 == 2 || y2 == 2)
	{
		if (y1 == 2)
		{
			for (int i = stt_gd2; i >= x2 / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (y2 == 2)
		{
			for (int i = stt_gd1; i >= x1 / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 -= cols;
			y1chay -= 3;
			if (y1chay == -1)
				break;
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 -= cols;
			y2chay -= 3;
			if (y2chay == -1)
				break;
		}

		if (y1chay == -1 && y2chay == -1)
			return true;

		stt_gd1 += cols;
		stt_gd2 += cols;
		y1chay += 3;
		y2chay += 3;

		if (y1chay > y2 || y2chay > y1) return false;

		if (y1chay == 2)
		{
			for (int i = pos2 - cols; i <= x2 / 5 + y1chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (y2chay == 2)
		{
			for (int i = pos1 - cols; i <= x1 / 5 + y2chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		if (x1 <= x2)
		{
			for (int i = stt_gd1 + 1; i <= x2 / 5 + y1chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= stt_gd2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - 1)
					return true;
			}
			return false;
		}

		else if (x1 >= x2)
		{
			for (int i = stt_gd2 + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = x2 / 5 + y1chay / 3 * cols; i <= stt_gd1 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd1 - 1)
					return true;
			}
			return false;
		}
	}
}
bool check_U_left(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int x1chay = x1 - 5;
	int x2chay = x2 - 5;
	int stt_gd1 = pos1 - 1;
	int stt_gd2 = pos2 - 1;
	/* =======   MẶC ĐỊNH    =======   */
	if (x1 == 4 && x2 == 4)
		return true;

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != -1)
		return false;
	if (kt[stt_gd2].ch != ' ' && stt_gd2 != -1)
		return false;


	else if (x1 == 4 || x2 == 4)
	{
		if (x1 == 4)
		{
			for (int i = stt_gd2; i >= x1 / 5 + y2 / 3 * cols; i--)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (x2 == 4)
		{
			for (int i = stt_gd1; i >= x2 / 5 + y1 / 3 * cols; i--)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}

	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 -= 1;
			x1chay -= 5;
			if (x1chay <= -1)
				break;
		}

		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 -= 1;
			x2chay -= 5;
			if (x2chay <= -1)
				break;
		}

		if (x1chay <= -1 && x2chay <= -1)
			return true;


		stt_gd1 += 1;
		stt_gd2 += 1;
		x1chay += 5;
		x2chay += 5;


		if (y1 <= y2)
		{
			for (int i = stt_gd1 + cols; i <= x1chay / 5 + y2 / 3 * cols; )
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (y1 >= y2)
		{
			for (int i = stt_gd2 + cols; i <= x2chay / 5 + y1 / 3 * cols; )
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
}
bool check_U_right(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int x1chay = x1 + 5;
	int x2chay = x2 + 5;
	int stt_gd1 = pos1 + 1;
	int stt_gd2 = pos2 + 1;
	/* =======   MẶC ĐỊNH    =======   */

	if (x1 == 5 * cols - 1 && x2 == 5 * cols - 1)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 5 * cols + 4)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 5 * cols + 4)
		return false;

	if (x1 == 5 * cols - 1 || x2 == 5 * cols - 1)
	{
		if (x1 == 5 * cols - 1)
		{
			for (int i = stt_gd2; i <= x1 / 5 + y2 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (x2 == 5 * cols - 1)
		{
			for (int i = stt_gd1; i <= x2 / 5 + y1 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 += 1;
			x1chay += 5;
			if (x1chay == 5 * cols + 4)
			{
				/*kt[stt_gd1].ch = ' ';*/
				break;
			}
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 += 1;
			x2chay += 5;
			if (x2chay == 5 * cols + 4)
			{
				/*kt[stt_gd2].ch = ' ';*/
				break;
			}
		}

		if (x1chay == 5 * cols + 4 && x2chay == 5 * cols + 4)
			return true;

		stt_gd1 -= 1;
		stt_gd2 -= 1;
		x1chay -= 5;
		x2chay -= 5;

		if (x1chay < x2 || x2chay < x1) return false;

		if (x1chay == 5 * cols - 1)
		{
			for (int i = pos2 + 1; i <= x1chay / 5 + y2 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (x2chay == 5 * cols - 1)
		{
			for (int i = pos1 + 1; i <= x2chay / 5 + y1 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		if (y1 <= y2)
		{
			for (int i = stt_gd1 + cols; i <= x1chay / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1chay / 5 + y2 / 3 * cols)
					return true;

				i += cols;
			}

			for (int i = x2chay / 5 + y1 / 3 * cols; i <= stt_gd2 - cols;)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - cols)
					return true;

				i += cols;
			}
			return false;
		}

		else if (y1 >= y2)
		{
			for (int i = stt_gd2 + cols; i <= x2chay / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					break;
				if (i == x2chay / 5 + y1 / 3 * cols)
					return true;
				i += cols;
			}

			for (int i = x1chay / 5 + y2 / 3 * cols; i <= stt_gd1 - cols;)
			{
				if (kt[i].ch != ' ')
					break;
				if (i == stt_gd1 - cols)
					return true;
				i += cols;
			}
			return false;
		}
	}
}
bool check_zic_zac_ngang(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int posleft = pos1 + 1;
	int posright = pos2 - 1;
	int xlchay = x1 + 5;
	int xrchay = x2 - 5;

	/*if (kt[posleft].ch != ' ' || kt[posright].ch != ' ')
		return false;*/

	if (y1 < y2)
	{
		if (kt[posleft].ch == ' ' && kt[posright].ch == ' ')
		{
			if (xlchay == xrchay)
			{
				for (int i = posleft + cols; i <= posright - cols; )
				{
					if (kt[i].ch != ' ')
						return false;

					if (i == posright - cols)
						return true;
					i += cols;
				}
			}
			else
			{
				while (kt[posleft].ch == ' ')
				{
					xlchay += 5;
					posleft += 1;
					if (xlchay >= 5 * cols + 4)
						break;
				}

				while (kt[posright].ch == ' ')
				{
					xrchay -= 5;
					posright -= 1;
					if (xrchay <= -1)
						break;
				}

				xlchay -= 5;
				posleft -= 1;
				xrchay += 5;
				posright += 1;

				if (xlchay < xrchay) return false;

				if (xlchay == xrchay)
				{
					for (int i = posleft + cols; i <= xlchay / 5 + y2 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							return false;

						i += cols;
					}

					return true;
				}
				else
				{
					for (int i = xrchay / 5 + y1 / 3 * cols; i <= posright - cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == posright - cols)
							return true;

						i += cols;
					}

					for (int i = posleft + cols; i <= xlchay / 5 + y2 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == xlchay / 5 + y2 / 3 * cols)
							return true;

						i += cols;
					}

					return false;
				}
			}
		}
	}

	else if (y1 > y2)
	{
		if (kt[posleft].ch == ' ' && kt[posright].ch == ' ')
		{
			if (xlchay = xrchay)
			{
				for (int i = posright + cols; i <= posleft - cols; )
				{
					if (kt[i].ch != ' ')
						return false;

					if (i == posleft - cols)
						return true;

					i += cols;
				}
			}
			else
			{
				while (kt[posleft].ch == ' ')
				{
					xlchay += 5;
					posleft += 1;
					if (xlchay >= 5 * cols + 4)
						break;
				}

				while (kt[posright].ch == ' ')
				{
					xrchay -= 5;
					posright -= 1;
					if (xrchay <= -1)
						break;
				}

				xlchay -= 5;
				posleft -= 1;
				xrchay += 5;
				posright += 1;

				if (xlchay < xrchay) return false;

				if (xlchay == xrchay)
				{
					for (int i = posright + cols; i <= xrchay / 5 + y1 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							return false;

						i += cols;
					}

					return true;
				}
				else
				{
					for (int i = posright + cols; i <= xrchay / 5 + y1 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == xrchay / 5 + y1 / 3 * cols)
							return true;

						i += cols;
					}

					for (int i = xlchay / 5 + y2 / 3 * cols; i <= pos1 - cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == pos1 - cols)
							return true;

						i += cols;
					}

					return false;
				}
			}
		}
	}
}
bool check_zic_zac_doc(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int postop = pos1 + cols;
	int posbot = pos2 - cols;
	int y1chay = y1 + 3;
	int y2chay = y2 - 3;

	/*if (kt[postop].ch != ' ' || kt[posbot].ch != ' ')
		return false;*/


	if (x1 < x2)
	{
		if (kt[postop].ch == ' ' && kt[posbot].ch == ' ')
		{
			if (y1chay == y2chay)
			{
				for (int i = postop + 1; i <= posbot - 1; i++)
				{
					if (kt[i].ch != ' ')
						return false;
				}
				return true;
			}
		}



		while (kt[postop].ch == ' ')
		{
			y1chay += 3;
			postop += cols;
			if (y1chay >= 3 * lines + 3)
				break;
		}
		while (kt[posbot].ch == ' ')
		{
			y2chay -= 3;
			postop -= cols;
			if (y2chay <= -1)
				break;
		}

		y1chay -= 3;
		postop -= cols;
		y2chay += 3;
		posbot += cols;


		if (y1chay == y2chay)
		{
			for (int i = postop + 1; i <= posbot - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else
		{
			for (int i = postop + 1; i <= x2 / 5 + y1chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= posbot - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}
	else if (x1 > x2)
	{
		if (kt[postop].ch == ' ' && kt[posbot].ch == ' ')
		{
			if (y1chay == y2chay)
			{
				for (int i = posbot + 1; i <= postop - 1; i++)
				{
					if (kt[i].ch != ' ')
						return false;
				}
				return true;
			}
		}

		if (kt[postop].ch != ' ' || kt[posbot].ch != ' ')
			return false;

		while (kt[postop].ch == ' ')
		{
			y1chay += 3;
			postop += cols;
			if (y1chay >= 3 * lines + 3)
				break;
		}
		while (kt[posbot].ch == ' ')
		{
			y2chay -= 3;
			posbot -= cols;
			if (y2chay <= -1)
				break;
		}

		y1chay -= 3;
		postop -= cols;
		y2chay += 3;
		posbot += cols;

		if (y1chay == y2chay)
		{
			for (int i = posbot + 1; i <= postop - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else
		{
			for (int i = posbot + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = y1chay / 3 * cols + x2 / 5; i <= postop - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}

}