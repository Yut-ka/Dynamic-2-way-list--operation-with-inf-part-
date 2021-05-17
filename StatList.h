#pragma once
#include <string>
#include <iostream>

struct TList_Item {
	int inf;
	TList_Item* left;
	TList_Item* right;
};

struct Dynamic_List {
public:
	TList_Item* pHead;
	Dynamic_List() {
		pHead = new TList_Item();
		pHead->left = pHead;
		pHead->right = pHead;
	}
};

	int Push_after(Dynamic_List* list, int inf1, int inf2) {
		TList_Item* pCurrent = list->pHead->right;
		TList_Item* pTemp = new TList_Item();
		while(pCurrent != list->pHead || list->pHead->right == list->pHead) {
			if (pCurrent->inf == inf1 || list->pHead->right == list->pHead) {
				pTemp->left = pCurrent;
				pTemp->right = pCurrent->right;
				pCurrent->right->left = pTemp;
				pCurrent->right = pTemp;
				pTemp->inf = inf2;
				return 1;
			}
			pCurrent = pCurrent->right;
		}
		return 0;
	}
	int Push_before(Dynamic_List* list, int inf1, int inf2) {
		TList_Item* pCurrent = list->pHead->right;
		TList_Item* pTemp = new TList_Item();
		while(pCurrent != list->pHead) {
			if (pCurrent->inf == inf1) {
				pCurrent->left->right = pTemp;
				pTemp->left = pCurrent->left;
				pTemp->right = pCurrent;
				pCurrent->left = pTemp;
				pTemp->inf = inf2;
				return 1;
			}
			pCurrent = pCurrent->right;
		}
		return 0;
	}
	std::string Delete(Dynamic_List* list, int inf) {
		TList_Item* pCurrent = list->pHead->right;
		while(pCurrent != list->pHead) {
			if (pCurrent->inf == inf) {
				pCurrent->left->right = pCurrent->right;
				pCurrent->right->left = pCurrent->left;
				delete(pCurrent);
				return "The number was deleted.";
			}
			pCurrent = pCurrent->right;
		}
		return "The number not found!";
	}

	std::string Get_right(Dynamic_List* list, int inf) {
		TList_Item* pCurrent = list->pHead;
		int i = 1;
		while (pCurrent->right != list->pHead) {
			pCurrent = pCurrent->right;
			if (pCurrent->inf == inf) return "The number with inf: | " + std::to_string(pCurrent->inf)+" | has index (on right side): | " + std::to_string(i) + " |.";
			i++;
		}
		return "The number with inf : | " + std::to_string(inf)+" | not found. ";
	}

	std::string Get_left(Dynamic_List* list, int inf) {
		TList_Item* pCurrent = list->pHead;
		int i = 1;
		while (pCurrent->left != list->pHead) {
			pCurrent = pCurrent->left;
			if (pCurrent->inf == inf) return "The number with inf: | " + std::to_string(pCurrent->inf) + " | has index (on left side): | " + std::to_string(i) + " |.";
			i++;
		}
		return "The number with inf : | " + std::to_string(inf) + " | not found. ";
	}

	std::string Show_right(Dynamic_List* list) {
		std::string str;
		TList_Item* pCurrent = list->pHead->right;
		while(pCurrent != list->pHead) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->right;
		}
		return str;
	}

	std::string Show_left(Dynamic_List* list) {
		std::string str;
		TList_Item* pCurrent = list->pHead->left;
		while (pCurrent != list->pHead) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->left;
		}
		return str;
	}