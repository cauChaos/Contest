#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int count = 0;

// 데이터형식
typedef struct {
	char member[MAX_SIZE];
	char group[MAX_SIZE];
}element;

// 노드의 구조
typedef struct treeNode {
	element key;
	struct treeNode* left;		// 왼쪽 트리에 대한 링크
	struct treeNode* right;		// 오른쪽 트리에 대한 링크
} treeNode;

void insertNode(treeNode **root, element x) {
	treeNode *nNode;		// 새 노드
	treeNode *qNode = NULL;		// 삽입할 자리를 찾기 위한 포인터변수
	treeNode *pNode = *root;		// 삽입할 노드의 부모노드를 저장하기 위한 포인터변수


	while (pNode != NULL) { // 탐색을 먼저 수행하여 삽입할 자리를 찾는다.
		if (strcmp(x.member, pNode->key.member) == 0) {// s1 = s2( strcmp 0 반환 )
			return;
		}
		// 같은 키가 아닌 것을 확인한 상태
		qNode = pNode;		// 삽입할 자리를 찾기 위해 pNode를 qNode로 넣는다.
		if (strcmp(x.member, pNode->key.member) < 0) {// s1 < s2( strcmp -1 반환)
			pNode = pNode->left;
		}
		else if (strcmp(x.member, pNode->key.member) > 0) {// s1 > s2( strcmp 1 반환)
			pNode = pNode->right;
		}
	}

	// 삽입할 자리를 찾았으니 삽입할 노드를 생성한다.
	nNode = (treeNode*)malloc(sizeof(treeNode));	// 새 노드의 공간을 할당한다.
	nNode->key = x;		// 새 노드 key를 x의 값으로 할당한다.(member와 group)
	nNode->left = NULL;		// 최초노드이기 때문에 왼쪽 링크 NULL
	nNode->right = NULL;		// 최초노드이기 때문에 오른쪽 링크 NULL


	if (qNode != NULL) { // 삽입할 자리의 부모노드와 비교 노드를 연결한다.
		if (strcmp(x.member, qNode->key.member) < 0) {
			qNode->left = nNode;
		}
		else if (strcmp(x.member, qNode->key.member) > 0) {
			qNode->right = nNode;
		}
	}
	else {
		*root = nNode;		// 비어 있다면 새로 만든 노드를 root로 넣는다.
	}
}

// 멤버에 해당하는 Group을 탐색(검색)하는 함수
treeNode* searchGroup(treeNode* root, char * member) {
	while (root != NULL) {
		if (strcmp(member, root->key.member) == 0) return root;
		else if (strcmp(member, root->key.member)<0) root = root->left;
		else if (strcmp(member, root->key.member)>0) root = root->right;
	}
	return root;
}

// Group에 해당하는  Member를 전부 출력하는 함수
void findMember(treeNode* root, char group[MAX_SIZE]) {          // 이진 탐색 트리를 중위 순회하면서 출력하는 연산
	if (root != NULL) {
		findMember(root->left, group);
		if (strcmp(root->key.group, group) == 0) {
			if (count == 0) {
				printf("%s", root->key.member);
				count++;
			}
			else {
				printf("\n");
				printf("%s", root->key.member);
			}
		}
		findMember(root->right, group);
	}
}


int main() {
	element e;
	treeNode* root = NULL;	// 최초 root 노드 NULL 값으로 초기화
	treeNode* foundedNode = NULL;	// 탐색에 필요한 Node NULL 값으로 초기화
	int n, m, j;
	int judge = 0;
	char ngroup[MAX_SIZE]= { 0 };
	char quiz[MAX_SIZE][MAX_SIZE] = { 0 };

	scanf("%d", &n);
	scanf("%d", &m);
	getchar();

	for (int i = 0; i < n; i++) {
		scanf("%s", e.group);
		scanf("%d", &j);
		for (int i = 0; i < j; i++) {
			scanf("%s", e.member);
			insertNode(&root, e);
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", quiz[i]);
		scanf("%d", &judge);
		if (judge == 0) {
			findMember(root, quiz[i]);
			if(i != m-1) {
				printf("\n");
				count = 0;
			}
		}
		else if (judge == 1) {
			foundedNode = searchGroup(root, quiz[i]);
			if (foundedNode != NULL) {
				if (i == m-1) {
					printf("%s", foundedNode->key.group);
				}
				else {
					printf("%s\n", foundedNode->key.group);
				}
			}
		}
	}
	return 0;
}
