/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:31 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/19 09:57:07 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../vector/vector.hpp"
// #include "map.hpp"
#include "avl_tree.hpp"
// #include "avl_source_code.hpp"
// int main() {
//   AVLTree tree_avl;
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
//       tree_avl.root = tree_avl.insert(tree_avl.root, new_node);
//       cout << endl;
//       break;
//     case 2:
//       cout << "SEARCH" << endl;
//       cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
//       cin >> val;
//       //new_node = tree_avl.iterativeSearch(val);
//       new_node = tree_avl.recursiveSearch(tree_avl.root, val);
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
//       new_node = tree_avl.recursiveSearch(tree_avl.root, val);
//       if (new_node != NULL) {
//         tree_avl.root = tree_avl.deleteNode(tree_avl.root, val);
//         cout << "Value Deleted" << endl;
//       } else {
//         cout << "Value NOT found" << endl;
//       }
//       break;
//     case 4:
//       cout << "PRINT 2D: " << endl;
//       tree_avl.print2D(tree_avl.root, 5);
//       cout << endl;
//       //cout <<"Print Level Order BFS: \n";
//       //tree_avl.printLevelOrderBFS(tree_avl.root);
//       //cout <<endl;
//       //	      cout <<"PRE-ORDER: ";
//       //	      tree_avl.printPreorder(tree_avl.root);
//       //	      cout<<endl;
//       //	      cout <<"IN-ORDER: ";
//       //	      tree_avl.printInorder(tree_avl.root);
//       //	      cout<<endl;
//       //	      cout <<"POST-ORDER: ";
//       //	      tree_avl.printPostorder(tree_avl.root);
//       break;
//     case 5:
//       cout << "TREE HEIGHT" << endl;
//       cout << "Height : " << tree_avl.height(tree_avl.root) << endl;
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
    ft::avl_tree<int, std::less<int> , std::allocator<int> > tree_avl;
    int val;
    int i   = 0 ;
    while (i < 2)
    {

      val = i+3;
  
      ft::nodes<int> * new_node = new ft::nodes<int>();
      new_node -> value = val;
      tree_avl.root = tree_avl.insert(tree_avl.root, new_node);      
      i++;
    }


    tree_avl.print2D(tree_avl.root, 5);
    int he = tree_avl.get_balance_height(tree_avl.root);
    std::cout << "he  = "<< he << std::endl;

}