//* 202131230 정윤혁 2022.06.04

#include "../22.06.04/04_BinarySearchTree.cpp"

//@     ==OUTPUT==
//@     Using preorder traversal
//@     Michael
//@     Jane
//@     Sophie
//@     Rose
//@     Richard
//@     Thomas
//@
//@     Using inorder traversal
//@     Jane
//@     Michael
//@     Richard
//@     Rose
//@     Sophie
//@     Thomas
//@
//@     Using postorder traversal
//@     Thomas
//@     Richard
//@     Rose
//@     Sophie
//@     Jane
//@     Michael
//@
//@     Searching :
//@     Is Sophie in the tree? true
//@     Is Mary in the tree? false

int main()
{
    BinarySearchTree<string> bct;

    bct.insert("Michael");
    bct.insert("Jane");
    bct.insert("Sophie");
    bct.insert("Thomas");
    bct.insert("Rose");
    bct.insert("Richard");

    cout << "Using preorder traversal" << endl;
    bct.preorder();
    cout << endl << endl;

    cout << "Using inorder traversal" << endl;
    bct.inorder();
    cout << endl << endl;

    cout << "Using postorder traversal" << endl;
    bct.postorder();
    cout << endl << endl;

    cout << "Searching : " << endl;
    cout << "Is Sophie in the tree? " << boolalpha;
    cout << bct.search("Sophie") << endl;
    cout << "Is Mary in the tree? " << boolalpha;
    cout << bct.search("Mary") << endl;

    return 0;
}