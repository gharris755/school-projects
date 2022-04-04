#ifndef BINARYTREE_H //guardds in place 
#define BINARYTREE_H

#include <iostream> //#includes to ensure certain libraries are implemented properly.
#include <fstream>
#include <string>
using namespace std;

class BinaryTree //Binary Tree class created.
{
	private:
		struct TreeNode //Structure to hold private member variables.
		{
			string value; //string variable that shows the value inside a node
			TreeNode* left; //pointer to use when moving through the binary tree
			TreeNode* right; // pointer to also use while while moving through the binary tree.
		};
		
		TreeNode* taxonomy_root_ptr; //pointer that points to the root of the binary tree.
		
		void insert(TreeNode*&, TreeNode*&); //void functions that are used to create the binary tree.
		void remove(TreeNode*&, string);
		void makeDeletion(TreeNode*&);
		void displayInOrder(TreeNode*) const;
	
	public:
	
		BinaryTree() //constructor to set the root to null;
		{
			taxonomy_root_ptr = NULL;
		}
		
		void insertNode(string nodeStringValue) //function that is called immediately when adding a new node and its value to the tree.
		{
			//create a new node
			TreeNode* newNode = new TreeNode;
			newNode->value = nodeStringValue;
			newNode->left = newNode->right = NULL;
			
			//now insert in correct location in tree
			insert(taxonomy_root_ptr, newNode);
		}
		
		void removeNode(string nodeStringValue)
		{
			remove(taxonomy_root_ptr, nodeStringValue);
		}
		
		void displayInOrder()
		{
			displayInOrder(taxonomy_root_ptr);
		}
        void GamePlay(); //function that goes through the game with the user.
        void playerWins(); //function called within GamePlay for when the computer can not guess the player's animal.
        
};

void BinaryTree::insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	if(nodePtr == NULL)
		nodePtr = newNode;
	else if(newNode->value < nodePtr->value)  //newNode needs to be inserted in the left subtree
		insert(nodePtr->left, newNode);
	else //newNode will be inserted in the right subtree
		insert(nodePtr->right, newNode);
}

void BinaryTree::remove(TreeNode* &nodePtr, string nodeStringValue)
{
	if(nodeStringValue < nodePtr->value) //string is in left subtree
		remove(nodePtr->left, nodeStringValue);
	else if(nodeStringValue > nodePtr->value) //string is in right subtree
		remove(nodePtr->right, nodeStringValue);
	else
		makeDeletion(nodePtr); //either null or the one to remove
}

void BinaryTree::makeDeletion(TreeNode* &nodePtr)
{
	TreeNode* tempNodePtr;
	
	//what if root?
	if(nodePtr == NULL) 
		cout << "Cannot delete empty node.\n";
	else if(nodePtr->right == NULL) //there is no child on the right
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; //reattach left child
		delete tempNodePtr;
	}
	else if(nodePtr->left == NULL) //there is no child on the left
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else //the node has two children
	{
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void BinaryTree::displayInOrder(TreeNode* nodePtr) const   //displays the list of node values from root to bottom of the tree.
{
	if(nodePtr != NULL)
	{
		displayInOrder(nodePtr->left); //left
		cout << nodePtr->value << "\n"; //print current node
		displayInOrder(nodePtr->right); //right
	}
}

void BinaryTree::GamePlay() //function for the guessing game.
{
    //nodes are inserted manually because I was unable to create the link from ifstream txt file to binary tree.
    insertNode("Are you a mammal?");
	insertNode("Are you bigger than a cat?");
	insertNode("Do you live underwater?");
	insertNode("Kangaroo");
	insertNode("Mouse");
	insertNode("Trout");
	insertNode("Robin");
    
    string response;
    
    TreeNode *current_ptr; //created current ptr to keep track of which node the game is on.
    current_ptr = taxonomy_root_ptr; //initialized current ptr to the root.
    if(current_ptr !=NULL) //if statement begins the game and traverses as long as the pointer is not NULL.
    {
        cout << "Are you a mammal?" << endl;
        getline(cin, response);
        if(response == "yes" || response == "Yes")
        {
            current_ptr = current_ptr->left;
            cout << "Are you bigger than a cat?"<< endl; 
            getline(cin, response);
            if(response == "yes" || response == "Yes")
            {   
                
                cout << "Are you a Kangaroo?" << endl;
                getline(cin,response);
                if(response == "Yes" || response == "yes")
                {
                    cout << "Yay I figured out your animal I win!"<< endl;
                    cout << "\n That was a great game! Do you want to play again? \n";
                    getline(cin, response);
                    if(response == "yes" || "Yes") //If computer wins takes in response if they would like to play again.
                    {
                        GamePlay(); //initializes next round if player wants to play again.
                    }

                }
                else
                {
                    playerWins(); //if user can't guess the right animal goes directly to playerWins function.
                }

            }
            else if(response == "no" || response == "No")
            {
                
                cout << "Are you a mouse?" << endl;
                getline(cin, response);
                if(response == "Yes" || response == "yes")
                {
                    cout << "Yay I figured out your animal I win!"<< endl;
                    cout << "\n That was a great game! Do you want to play again? \n";
                    getline(cin, response);
                    if(response == "yes" || "Yes")
                    {
                        GamePlay(); // same process as the responses change from yes to no.
                    }

                }
                else
                {
                    playerWins();
                }

            }
            else
            {
                cout << "Invalid Response" << endl;
                GamePlay();
            }
            
        }
        else // tree is traversed to the right side of the tree from root.
        {
            if(response == "no" || response == "No")
            {
                current_ptr = current_ptr->right;
                cout << "Do you live underwater?" << endl;
                getline(cin, response);
                if(response == "yes" || response == "Yes")
                {
                    current_ptr = current_ptr->left;
                    cout << "Are you a trout?" << endl;
                    getline(cin, response);
                    if(response == "Yes" || response == "yes")
                    {
                        cout << "Yay I figured out your animal I win!"<< endl;
                        cout << "\n That was a great game! Do you want to play again? \n";
                        getline(cin, response);
                        if(response == "yes" || "Yes")
                        {
                            GamePlay();
                        }
                        else
                        {
                            cout << "\nGreat game! Let's play again soon!\n";
                        }
                        
                        
                    }
                    else
                    {
                        playerWins();
                    }
                    
                }//continuing to traverse through the questions.
                else if(response == "no" || response == "No")
                {
                    
                    cout << "Are you a robin?" << endl;
                    getline(cin, response);
                    if(response == "Yes" || response == "yes")
                    {
                        cout << "Yay I figured out your animal I win!"<< endl;
                        cout << "\n That was a great game! Do you want to play again? \n";
                        getline(cin, response);
                        if(response == "yes" || "Yes")
                        {
                            GamePlay();
                        }
                        else
                        {
                            cout << "\nGreat game! Let's play again soon!\n";
                        }


                    }
                    else
                    {
                        playerWins();

                    }
                
                }
                else
                {
                    cout << "Invalid Response" << endl;
                    GamePlay();
                } 
            }    
            
        }    
        
    }

 

}

void BinaryTree::playerWins() // function implemented when computer can't guess the player's animal.
{
    string answer;
    string question;
    string response;

    

    cout << "Looks like you WIN!" << endl;
    cout << "\nI am stumped what was the animal you were thinking of?" << endl;
    getline(cin, answer);//asks the player what their animal was and takes in response.

    cout << "That was a great animal to think of!" << endl;
    cout << "What would be a good question to ask for " << answer << "?" << endl;
    getline(cin, question); //takes in a question to how it can remember the animal next time.

    ofstream ofs("animals.txt", std::ofstream::app); //appends the text file so that the new question and answer is added for a different round.
    ofs << question << "\n";
    ofs << answer << "\n";
    
    insertNode(question); //puts the new question and answer in a node to traverse through the tree when playing multiple rounds.
    insertNode(answer);

    
    cout << endl;

    cout << "That was a great game! Do you want to play again?" << endl; //Asks player if they want to play again. If they do initiate GamePlay again.
    getline(cin, response);
    if(response == "yes" || response == "Yes")
    {
        GamePlay();
    }
    else if(response == "No" || response == "no")
    {
        cout << "\nGreat game! Let's play again soon!\n";
        //For when player does not wish to play again.
    }
    else
    {
        cout << "Invalid Response" << endl;
        cout << "\n Do you want to play again?" << endl;
        getline(cin, response);
        if(response == "yes" || response == "Yes")
        {
            GamePlay();
        }
        else if(response == "No" || response == "no")
        {
            cout << "\nGreat game! Let's play again soon!\n";
            //For when player does not wish to play again.
        }
    }




}
#endif  //ending guard for header file.

//For this program I did reference the binary tree node functions
//from examples in our course material that spoke about BST of strings.