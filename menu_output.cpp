#include "menu.h"
#include <iostream>
#include <iomanip>

#define TAB 40

using namespace std;

int main_menu() {				//¸ÞÀÎ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. ¿µ¾÷ÇÏ±â" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. »óÇ°°ü¸®" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ¸ÅÃâ°ü¸®" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. È¯°æ¼³Á¤" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 5. ÇÁ·Î±×·¥ ´Ý±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:¿µ¾÷ÇÏ±â , 2:»óÇ°°ü¸®, 3:¸ÅÃâ°ü¸®, 4:È¯°æ¼³Á¤, 5:ÇÁ·Î±×·¥ ´Ý±â

	return menu;
}


int sell_menu() {				// ¸ÞÀÎ¸Þ´º -> 1.¿µ¾÷ÇÏ±â ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> ¿µ¾÷ÇÏ±â" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. »óÇ°ÆÇ¸Å ¹× È¯ºÒ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. ¿µ¼öÁõÁ¶È¸" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ÀÏÀÚº° ¿µ¼öÁõ¸ñ·Ï º¸±â" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:»óÇ°ÆÇ¸Å, 2.¿µ¼öÁõÁ¶È¸, 3. ÀÏÀÚº° ¿µ¼öÁõ¸ñ·Ï º¸±â, 4.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}


int product_menu() {			// ¸ÞÀÎ¸Þ´º -> 2.»óÇ°°ü¸® ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> »óÇ°°ü¸®" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. »óÇ°µî·Ï" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. »óÇ°¼öÁ¤" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. »óÇ°Á¦°Å" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. Æ¯Á¤»óÇ° Á¤º¸Á¶È¸" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 5. ¸ðµç»óÇ° Á¤º¸Á¶È¸" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 6. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:»óÇ°µî·Ï, 2.»óÇ°¼öÁ¤, 3.»óÇ°Á¦°Å, 4.Æ¯Á¤»óÇ°Á¶È¸, 5.¸ðµç»óÇ°Á¶È¸, 6.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}


int statistics_menu() {		// ¸ÞÀÎ¸Þ´º -> 3.¸ÅÃâ°ü¸® ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> ¸ÅÃâ°ü¸®" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. ¸ÅÃâ Åë°è" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. ÆÇ¸Å·® Åë°è" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:¸ÅÃâ Åë°è, 2.ÆÇ¸Å·® Åë°è, 3.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}

int statistics_sell_menu() {			// ¸ÞÀÎ¸Þ´º -> 3.¸ÅÃâ°ü¸® -> 1.¸ÅÃâÅë°è ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> ¸ÅÃâ°ü¸® -> ¸ÅÃâÅë°è" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. ±ÝÀÏ ¸ÅÃâÇöÈ²" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. Æ¯Á¤ÀÏ ¸ÅÃâÇöÈ²" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ¿ùº° ¸ÅÃâÇöÈ²" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. ³âº° ¸ÅÃâÇöÈ²" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 5. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:±ÝÀÏ¸ÅÃâÇöÈ², 2.Æ¯Á¤ÀÏ ¸ÅÃâÇöÈ², 3.¿ùº°¸ÅÃâÇöÈ², 4.¿¬º°¸ÅÃâÇöÈ², 5.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}


int statistics_product_menu() {			// ¸ÞÀÎ¸Þ´º -> 3.¸ÅÃâ°ü¸® -> 2.ÆÇ¸Å·®Åë°è ¸Þ´º ¹® Ãâ·Â
	int menu;

	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> ¸ÅÃâ°ü¸® -> ÆÇ¸Å·® Åë°è" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. ±ÝÀÏ ÆÇ¸Å·® ÃßÀÌ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. Æ¯Á¤ÀÏ ÆÇ¸Å·® ÃßÀÌ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ¿ùº° ÆÇ¸Å·® ÃßÀÌ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. ³âº° ÆÇ¸Å·® ÃßÀÌ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 5. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:±ÝÀÏ ÆÇ¸Å·® ÃßÀÌ, 2:Æ¯Á¤ÀÏ ÆÇ¸Å·® ÃßÀÌ, 3:¿ùº° ÆÇ¸Å·® ÃßÀÌ, 4:³âº° ÆÇ¸Å·® ÃßÀÌ, 5.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}


int configuration_menu() {		// ¸ÞÀÎ¸Þ´º -> 4.È¯°æ¼³Á¤ ¸Þ´º ¹® Ãâ·Â
	int menu;
	cout << "\n\n¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	cout << setw(TAB) << left << "¦¢ ¸ÞÀÎ¸Þ´º -> È¯°æ¼³Á¤" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 1. Æ÷½º¹øÈ£ º¯°æ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 2. ·Î±×ÀÎ Á¤º¸ È®ÀÎ" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 3. ´Ù¸¥ °èÁ¤À¸·Î ·Î±×ÀÎÇÏ±â" << "¦¢\n";
	cout << setw(TAB) << left << "¦¢ 4. ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â" << "¦¢\n";
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
	cout << "¸Þ´º ¼±ÅÃ : ";
	cin >> menu; // 1:Æ÷½º¹øÈ£ º¯°æ, 2.·Î±×ÀÎ Á¤º¸ È®ÀÎ, 3.´Ù¸¥ °èÁ¤À¸·Î ·Î±×ÀÎÇÏ±â, 4.ÀÌÀü¸Þ´º·Î µ¹¾Æ°¡±â

	return menu;
}
