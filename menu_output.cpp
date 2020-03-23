#include "menu.h"
#include <iostream>
#include <iomanip>

#define TAB 40

using namespace std;

int main_menu() {				//詭檣詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 艙機ж晦" << "弛\n";
	cout << setw(TAB) << left << "弛 2. 鼻ヶ婦葬" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 衙轎婦葬" << "弛\n";
	cout << setw(TAB) << left << "弛 4. �秣瞍麥�" << "弛\n";
	cout << setw(TAB) << left << "弛 5. Щ煎斜極 殘晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:艙機ж晦 , 2:鼻ヶ婦葬, 3:衙轎婦葬, 4:�秣瞍麥�, 5:Щ煎斜極 殘晦

	return menu;
}


int sell_menu() {				// 詭檣詭景 -> 1.艙機ж晦 詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> 艙機ж晦" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 鼻ヶっ衙 塽 �笑�" << "弛\n";
	cout << setw(TAB) << left << "弛 2. 艙熱隸褻��" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 橾濠滌 艙熱隸跡煙 爾晦" << "弛\n";
	cout << setw(TAB) << left << "弛 4. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:鼻ヶっ衙, 2.艙熱隸褻��, 3. 橾濠滌 艙熱隸跡煙 爾晦, 4.檜瞪詭景煎 給嬴陛晦

	return menu;
}


int product_menu() {			// 詭檣詭景 -> 2.鼻ヶ婦葬 詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> 鼻ヶ婦葬" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 鼻ヶ蛔煙" << "弛\n";
	cout << setw(TAB) << left << "弛 2. 鼻ヶ熱薑" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 鼻ヶ薯剪" << "弛\n";
	cout << setw(TAB) << left << "弛 4. か薑鼻ヶ 薑爾褻��" << "弛\n";
	cout << setw(TAB) << left << "弛 5. 賅萇鼻ヶ 薑爾褻��" << "弛\n";
	cout << setw(TAB) << left << "弛 6. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:鼻ヶ蛔煙, 2.鼻ヶ熱薑, 3.鼻ヶ薯剪, 4.か薑鼻ヶ褻��, 5.賅萇鼻ヶ褻��, 6.檜瞪詭景煎 給嬴陛晦

	return menu;
}


int statistics_menu() {		// 詭檣詭景 -> 3.衙轎婦葬 詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> 衙轎婦葬" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 衙轎 鱔啗" << "弛\n";
	cout << setw(TAB) << left << "弛 2. っ衙榆 鱔啗" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:衙轎 鱔啗, 2.っ衙榆 鱔啗, 3.檜瞪詭景煎 給嬴陛晦

	return menu;
}

int statistics_sell_menu() {			// 詭檣詭景 -> 3.衙轎婦葬 -> 1.衙轎鱔啗 詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> 衙轎婦葬 -> 衙轎鱔啗" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 旎橾 衙轎⑷��" << "弛\n";
	cout << setw(TAB) << left << "弛 2. か薑橾 衙轎⑷��" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 錯滌 衙轎⑷��" << "弛\n";
	cout << setw(TAB) << left << "弛 4. 喇滌 衙轎⑷��" << "弛\n";
	cout << setw(TAB) << left << "弛 5. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:旎橾衙轎⑷��, 2.か薑橾 衙轎⑷��, 3.錯滌衙轎⑷��, 4.翱滌衙轎⑷��, 5.檜瞪詭景煎 給嬴陛晦

	return menu;
}


int statistics_product_menu() {			// 詭檣詭景 -> 3.衙轎婦葬 -> 2.っ衙榆鱔啗 詭景 僥 轎溘
	int menu;

	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> 衙轎婦葬 -> っ衙榆 鱔啗" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. 旎橾 っ衙榆 蹺檜" << "弛\n";
	cout << setw(TAB) << left << "弛 2. か薑橾 っ衙榆 蹺檜" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 錯滌 っ衙榆 蹺檜" << "弛\n";
	cout << setw(TAB) << left << "弛 4. 喇滌 っ衙榆 蹺檜" << "弛\n";
	cout << setw(TAB) << left << "弛 5. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:旎橾 っ衙榆 蹺檜, 2:か薑橾 っ衙榆 蹺檜, 3:錯滌 っ衙榆 蹺檜, 4:喇滌 っ衙榆 蹺檜, 5.檜瞪詭景煎 給嬴陛晦

	return menu;
}


int configuration_menu() {		// 詭檣詭景 -> 4.�秣瞍麥� 詭景 僥 轎溘
	int menu;
	cout << "\n\n忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	cout << setw(TAB) << left << "弛 詭檣詭景 -> �秣瞍麥�" << "弛\n";
	cout << setw(TAB) << left << "弛" << "弛\n";
	cout << setw(TAB) << left << "弛 1. ん蝶廓�� 滲唳" << "弛\n";
	cout << setw(TAB) << left << "弛 2. 煎斜檣 薑爾 �挫�" << "弛\n";
	cout << setw(TAB) << left << "弛 3. 棻艇 啗薑戲煎 煎斜檣ж晦" << "弛\n";
	cout << setw(TAB) << left << "弛 4. 檜瞪詭景煎 給嬴陛晦" << "弛\n";
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
	cout << "詭景 摹鷗 : ";
	cin >> menu; // 1:ん蝶廓�� 滲唳, 2.煎斜檣 薑爾 �挫�, 3.棻艇 啗薑戲煎 煎斜檣ж晦, 4.檜瞪詭景煎 給嬴陛晦

	return menu;
}
