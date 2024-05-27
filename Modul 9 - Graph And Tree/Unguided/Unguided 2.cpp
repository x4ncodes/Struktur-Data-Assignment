    /*
    Axandio Biyanatul Lizan - 2311102179
    */
    
    #include <iostream>
    using namespace std;

    // PROGRAM BINARY TREE
    // Deklarasi Pohon
    struct Pohon {
        char data;
        Pohon *left, *right, *parent; // pointer
    };

    // pointer global
    Pohon *root;

    // Inisialisasi
    void init() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }

    Pohon *newPohon(char data) {
        Pohon *node = new Pohon();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        return node;
    }

    void buatNode(char data) {
        if (isEmpty()) {
            root = newPohon(data);
            cout << "\nHooorayyy, Node " << data << " berhasil dibuat menjadi root." << endl;
        } else {
            cout << "\nPohon sudah dibuat" << endl;
        }
    }

    Pohon *insertLeft(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy! Buat tree terlebih dahulu!" << endl;
            return NULL;
        } else {
            if (node->left != NULL) {
                cout << "\nyahhhh... Node " << node->data << " sudah ada child kiri!" << endl;
                return NULL;
            } else {
                Pohon *baru = newPohon(data);
                baru->parent = node;
                node->left = baru;
                cout << "\nYesss!! Node " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
            }
        }
    }

    Pohon *insertRight(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! buat tree terlebih dahulu!" << endl;
            return NULL;
        } else {
            if (node->right != NULL) {
                cout << "\nYahhh... Node " << node->data << " sudah ada child kanan!" << endl;
                return NULL;
            } else {
                Pohon *baru = newPohon(data);
                baru->parent = node;
                node->right = baru;
                cout << "\nYesss!! Node " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
            }
        }
    }

    void update(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! buat tree terlebih dahulu!" << endl;
        } else {
            if (!node)
                cout << "\nNode yang ingin diganti tidak ada!!" << endl;
            else {
                char temp = node->data;
                node->data = data;
                cout << "\nHooorayy!! Node " << temp << " berhasil diubah menjadi " << data << endl;
            }
        }
    }

    void retrieve(Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!" << endl;
        } else {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else {
                cout << "\nData node : " << node->data << endl;
            }
        }
    }

    void find(Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!" << endl;
        } else {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else {
                cout << "\nData Node : " << node->data << endl;
                cout << "Root : " << root->data << endl;
                if (!node->parent)
                    cout << "Parent : (tidak punya parent)" << endl;
                else
                    cout << "Parent : " << node->parent->data << endl;
                if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                    cout << "Sibling : " << node->parent->left->data << endl;
                else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                    cout << "Sibling : " << node->parent->right->data << endl;
                else
                    cout << "Sibling : (tidak punya sibling)" << endl;
                if (!node->left)
                    cout << "Child Kiri : (tidak punya Child kiri)" << endl;
                else
                    cout << "Child Kiri : " << node->left->data << endl;
                if (!node->right)
                    cout << "Child Kanan : (tidak punya Child kanan)" << endl;
                else
                    cout << "Child Kanan : " << node->right->data << endl;
            }
        }
    }

    void showChild(Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!" << endl;
        } else {
            if (!node) {
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            } else {
                cout << "\nNode " << node->data << " Child: " << endl;
                if (node->left)
                    cout << "Child Kiri : " << node->left->data << endl;
                else
                    cout << "Child Kiri : (tidak punya Child kiri)" << endl;
                if (node->right)
                    cout << "Child Kanan : " << node->right->data << endl;
                else
                    cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            }
        }
    }

    // Penelusuran (Traversal)
    // preOrder
    void preOrder(Pohon *node) {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void showDescendants(Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!" << endl;
        } else {
            if (!node) {
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            } else {
                cout << "\nDescendants of node " << node->data << " : ";
                preOrder(node);
                cout << endl;
            }
        }
    }

    // Penelusuran (Traversal)
    // inOrder
    void inOrder(Pohon *node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }

    // postOrder
    void postOrder(Pohon *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }

    // Hapus Node Tree
    void deleteTree(Pohon *node) {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }

    // Hapus SubTree
    void deleteSub(Pohon *node) {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!" << endl;
        } else {
            deleteTree(node->left);
            deleteTree(node->right);
            cout << "\nHoorayy!! Node subtree " << node->data << " berhasil dihapus." << endl;
        }
    }

    // Hapus Tree
    void clear() {
        if (isEmpty()) {
            cout << "\nHeyy!! Buat tree terlebih dahulu!!" << endl;
        } else {
            deleteTree(root);
            cout << "\nHoorayy!! Pohon berhasil dihapus." << endl;
        }
    }

    // Cek Size Tree
    int size(Pohon *node) {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }

    // Cek Height Level Tree
    int height(Pohon *node) {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }

    // Karakteristik Tree
    void characteristic() {
        int s = size(root);
        int h = height(root);
        cout << "\nSize Tree : " << s << endl;
        cout << "Height Tree : " << h << endl;
        if (h != 0)
            cout << "Average Node of Tree : " << s / h << endl;
        else
            cout << "Average Node of Tree : 0" << endl;
    }

    int main() {
        int choice;
        char axandio_2311102179, parentData, direction;
        Pohon *parentNode, *tempNode;
        
        do {
            cout << "\n=-=-=-= YOOO WELCOME TO Axan's Node Pohon =-=-=-=\n";
            cout << "1. Buat Node Root\n";
            cout << "2. Tambah Node Kiri\n";
            cout << "3. Tambah Node Kanan\n";
            cout << "4. Update Node\n";
            cout << "5. Retrieve Node\n";
            cout << "6. Find Node\n";
            cout << "7. Show Child\n";
            cout << "8. Show Descendants\n";
            cout << "9. PreOrder Traversal\n";
            cout << "10. InOrder Traversal\n";
            cout << "11. PostOrder Traversal\n";
            cout << "12. Show Characteristics\n";
            cout << "13. Clear Tree\n";
            cout << "14. Exit\n";
            cout << "Pilih menu: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "Masukkan data root: ";
                    cin >> axandio_2311102179;
                    buatNode(axandio_2311102179);
                    break;
                case 2:
                    cout << "Masukkan data parent: ";
                    cin >> parentData;
                    cout << "Masukkan data node kiri: ";
                    cin >> axandio_2311102179;
                    parentNode = root;
                    while (parentNode && parentNode->data != parentData) {
                        if (parentNode->left && parentNode->left->data == parentData)
                            parentNode = parentNode->left;
                        else if (parentNode->right && parentNode->right->data == parentData)
                            parentNode = parentNode->right;
                        else if (parentNode->left)
                            parentNode = parentNode->left;
                        else if (parentNode->right)
                            parentNode = parentNode->right;
                        else
                            parentNode = NULL;
                    }
                    if (parentNode) {
                        insertLeft(axandio_2311102179, parentNode);
                    } else {
                        cout << "Parent tidak ditemukan!" << endl;
                    }
                    break;
                case 3:
                    cout << "Masukkan data parent: ";
                    cin >> parentData;
                    cout << "Masukkan data node kanan: ";
                    cin >> axandio_2311102179;
                    parentNode = root;
                    while (parentNode && parentNode->data != parentData) {
                        if (parentNode->left && parentNode->left->data == parentData)
                            parentNode = parentNode->left;
                        else if (parentNode->right && parentNode->right->data == parentData)
                            parentNode = parentNode->right;
                        else if (parentNode->left)
                            parentNode = parentNode->left;
                        else if (parentNode->right)
                            parentNode = parentNode->right;
                        else
                            parentNode = NULL;
                    }
                    if (parentNode) {
                        insertRight(axandio_2311102179, parentNode);
                    } else {
                        cout << "Parent tidak ditemukan!" << endl;
                    }
                    break;
                case 4:
                    cout << "Masukkan data node yang ingin diupdate: ";
                    cin >> parentData;
                    cout << "Masukkan data baru: ";
                    cin >> axandio_2311102179;
                    tempNode = root;
                    while (tempNode && tempNode->data != parentData) {
                        if (tempNode->left && tempNode->left->data == parentData)
                            tempNode = tempNode->left;
                        else if (tempNode->right && tempNode->right->data == parentData)
                            tempNode = tempNode->right;
                        else if (tempNode->left)
                            tempNode = tempNode->left;
                        else if (tempNode->right)
                            tempNode = tempNode->right;
                        else
                            tempNode = NULL;
                    }
                    if (tempNode) {
                        update(axandio_2311102179, tempNode);
                    } else {
                        cout << "Node tidak ditemukan!" << endl;
                    }
                    break;
                case 5:
                    cout << "Masukkan data node yang ingin diretrieve: ";
                    cin >> axandio_2311102179;
                    tempNode = root;
                    while (tempNode && tempNode->data != axandio_2311102179) {
                        if (tempNode->left && tempNode->left->data == axandio_2311102179)
                            tempNode = tempNode->left;
                        else if (tempNode->right && tempNode->right->data == axandio_2311102179)
                            tempNode = tempNode->right;
                        else if (tempNode->left)
                            tempNode = tempNode->left;
                        else if (tempNode->right)
                            tempNode = tempNode->right;
                        else
                            tempNode = NULL;
                    }
                    if (tempNode) {
                        retrieve(tempNode);
                    } else {
                        cout << "Node tidak ditemukan!" << endl;
                    }
                    break;
                case 6:
                    cout << "Masukkan data node yang ingin dicari: ";
                    cin >> axandio_2311102179;
                    tempNode = root;
                    while (tempNode && tempNode->data != axandio_2311102179) {
                        if (tempNode->left && tempNode->left->data == axandio_2311102179)
                            tempNode = tempNode->left;
                        else if (tempNode->right && tempNode->right->data == axandio_2311102179)
                            tempNode = tempNode->right;
                        else if (tempNode->left)
                            tempNode = tempNode->left;
                        else if (tempNode->right)
                            tempNode = tempNode->right;
                        else
                            tempNode = NULL;
                    }
                    if (tempNode) {
                        find(tempNode);
                    } else {
                        cout << "Node tidak ditemukan!" << endl;
                    }
                    break;
                case 7:
                    cout << "Masukkan data node yang ingin ditampilkan child-nya: ";
                    cin >> axandio_2311102179;
                    tempNode = root;
                    while (tempNode && tempNode->data != axandio_2311102179) {
                        if (tempNode->left && tempNode->left->data == axandio_2311102179)
                            tempNode = tempNode->left;
                        else if (tempNode->right && tempNode->right->data == axandio_2311102179)
                            tempNode = tempNode->right;
                        else if (tempNode->left)
                            tempNode = tempNode->left;
                        else if (tempNode->right)
                            tempNode = tempNode->right;
                        else
                            tempNode = NULL;
                    }
                    if (tempNode) {
                        showChild(tempNode);
                    } else {
                        cout << "Node tidak ditemukan!" << endl;
                    }
                    break;
                case 8:
                    cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
                    cin >> axandio_2311102179;
                    tempNode = root;
                    while (tempNode && tempNode->data != axandio_2311102179) {
                        if (tempNode->left && tempNode->left->data == axandio_2311102179)
                            tempNode = tempNode->left;
                        else if (tempNode->right && tempNode->right->data == axandio_2311102179)
                            tempNode = tempNode->right;
                        else if (tempNode->left)
                            tempNode = tempNode->left;
                        else if (tempNode->right)
                            tempNode = tempNode->right;
                        else
                            tempNode = NULL;
                    }
                    if (tempNode) {
                        showDescendants(tempNode);
                    } else {
                        cout << "Node tidak ditemukan!" << endl;
                    }
                    break;
                case 9:
                    cout << "\nPreOrder :" << endl;
                    preOrder(root);
                    cout << "\n" << endl;
                    break;
                case 10:
                    cout << "InOrder :" << endl;
                    inOrder(root);
                    cout << "\n" << endl;
                    break;
                case 11:
                    cout << "PostOrder :" << endl;
                    postOrder(root);
                    cout << "\n" << endl;
                    break;
                case 12:
                    characteristic();
                    break;
                case 13:
                    clear();
                    break;
                case 14:
                    cout << "See You Next Time Traveler!!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
        } while (choice != 14);

        return 0;
    }
