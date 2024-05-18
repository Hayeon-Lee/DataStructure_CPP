#include "Tree.h"
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;

int main() {

    int n = 0;
    cout << "첫번째 트리를 만들 때 필요한 노드의 개수를 입력하세요.: ";
    cin >> n;

    int* arr = new int[n];

    cout << "삽입하고 싶은 노드의 데이터를 입력하세요." << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << "번째 노드: ";
        cin >> arr[i];
    }

    Tree<int> tree(arr[0]);
    tree.buildTree(arr, n);

    cout <<  setw(10) << "첫번째 트리 전위순회(Preorder):   ";
    tree.Preorder(tree.getRoot());
    cout << endl;

    cout << setw(10) <<"첫번째 트리 중위순회(Inorder):    " ;
    tree.Inorder(tree.getRoot());
    cout << endl;

    cout << setw(10) << "첫번째 트리 후위순회(Postorder):  ";
    tree.Postorder(tree.getRoot());
    cout << endl;

    cout << "\n두번째 트리를 만들 때 필요한 노드의 개수를 입력하세요.: ";
    cin >> n;
    int* arr2 = new int[n];

    cout << "삽입하고 싶은 노드의 데이터를 입력하세요." << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "번째 노드: ";
        cin >> arr2[i];
    }
    Tree<int> tree2(arr2[0]);
    tree2.buildTree(arr2, n);

    cout << setw(10) << "두번째 트리 전위순회(Preorder):   ";
    tree2.Preorder(tree2.getRoot());
    cout << endl;

    cout << setw(10) << "두번째 트리 중위순회(Inorder):    ";
    tree2.Inorder(tree2.getRoot());
    cout << endl;

    cout << setw(10) << "두번째 트리 후위순회(Postorder):  ";
    tree2.Postorder(tree2.getRoot());
    cout << endl;

    bool result = tree.Equal(tree.getRoot(), tree2.getRoot());
    if (result == true) cout << "\n두 트리는 같은 트리입니다." << endl;
    else cout << "\n두 트리는 다른 트리입니다." << endl;
}
