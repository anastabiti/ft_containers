/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/18 14:51:11 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../vector/vector.hpp"
#include "map.hpp"
#include "avl_tree.hpp"
// #include "avl_source_code.hpp"
// int main() {
//   AVLTree obj;
//   int option, val;

//   do {
//     cout << "What operation do you want to perform? " <<
//       " Select Option number. Enter 0 to exit." << endl;
//     cout << "1. Insert Node" << endl;
//     cout << "2. Search Node" << endl;
//     cout << "3. Delete Node" << endl;
//     cout << "4. Print/Traversal AVL Tree values" << endl;
//     cout << "5. Height of Tree" << endl;
//     cout << "6. Clear Screen" << endl;
//     cout << "0. Exit Program" << endl;

//     cin >> option;
//     //Node n1;
//     TreeNode * new_node = new TreeNode();

//     switch (option) {
//     case 0:
//       break;
//     case 1:
//       cout << "AVL INSERT" << endl;
//       cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
//       cin >> val;
//       new_node -> value = val;
//       obj.root = obj.insert(obj.root, new_node);
//       cout << endl;
//       break;
//     case 2:
//       cout << "SEARCH" << endl;
//       cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
//       cin >> val;
//       //new_node = obj.iterativeSearch(val);
//       new_node = obj.recursiveSearch(obj.root, val);
//       if (new_node != NULL) {
//         cout << "Value found" << endl;
//       } else {
//         cout << "Value NOT found" << endl;
//       }
//       break;
//     case 3:
//       cout << "DELETE" << endl;
//       cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
//       cin >> val;
//       new_node = obj.recursiveSearch(obj.root, val);
//       if (new_node != NULL) {
//         obj.root = obj.deleteNode(obj.root, val);
//         cout << "Value Deleted" << endl;
//       } else {
//         cout << "Value NOT found" << endl;
//       }
//       break;
//     case 4:
//       cout << "PRINT 2D: " << endl;
//       obj.print2D(obj.root, 5);
//       cout << endl;
//       //cout <<"Print Level Order BFS: \n";
//       //obj.printLevelOrderBFS(obj.root);
//       //cout <<endl;
//       //	      cout <<"PRE-ORDER: ";
//       //	      obj.printPreorder(obj.root);
//       //	      cout<<endl;
//       //	      cout <<"IN-ORDER: ";
//       //	      obj.printInorder(obj.root);
//       //	      cout<<endl;
//       //	      cout <<"POST-ORDER: ";
//       //	      obj.printPostorder(obj.root);
//       break;
//     case 5:
//       cout << "TREE HEIGHT" << endl;
//       cout << "Height : " << obj.height(obj.root) << endl;
//       break;
//     case 6:
//       system("cls");
//       break;
//     default:
//       cout << "Enter Proper Option number " << endl;
//     }

//   } while (option != 0);

//   return 0;
// }





int main()
{
    // ft::vector< std::pair <int, int> > vecc;
    // std::vector< int > vecc;
    // size_t  i = 0 ;
    // while (i< 10000000)
    // {
    //     vecc.push_back( i*3);
    //     // vecc.push_back( std::make_pair(i,i*3));
    //     i++;
    // }
    
    // ft::avl_tree<int, std::less<int>, std::allocator<int> > tes;
    // // std::map< int, int> mapp;
    // ft::map< int, int> mapp;
    // size_t x = 0;


    
    
    ft::nodes<int> f1(11);
    ft::nodes<int> f2(2);
    ft::nodes<int> f3(3);
    ft::nodes<int> f4(4);
    ft::nodes<int> *full;
    ft::nodes<int> *full1;
    ft::nodes<int> *full2;
    
    // ft::avl_tree<int, std::less<int> , std::allocator<int> > lst;
    ft::avl_tree<int, std::less<int> , std::allocator<int> > tree;
    
    full = tree.insert(tree.root, &f1);
    //   tree.insert(full, &f2);
    // tree.insert(full, &f3);
    // tree.insert(tree.root, &f1);
    // tree.insert(tree.root, &f2);
    tree.print2D(full,1);

}