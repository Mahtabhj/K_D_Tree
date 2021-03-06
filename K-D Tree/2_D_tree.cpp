#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

const int k=3;

struct Node
{
	int point[k];
	Node *left, *right;
};

struct Node *root = NULL;

struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;
	for (int i=0; i<k; i++)
        {
        temp->point[i] = arr[i];
        }

	temp->left = temp->right = NULL;
	return temp;
}

bool arePointsSame(int point1[], int point2[])
        {
                for (int i = 0; i < k; ++i)
                    if (point1[i] != point2[i])
                        return false;

                return true;
        }

bool searchRec(Node* root, int point[], unsigned depth)
        {
                if (root == NULL)
                            return false;
                if (arePointsSame(root->point, point))
                            {   cout<<"Depth : "<<"----"<<depth<<endl;
                                return true;
                            }
                unsigned cd = depth % k;
                if (point[cd] < root->point[cd])
                            return searchRec(root->left, point, depth + 1);

                return searchRec(root->right, point, depth + 1);
        }
void traverse(Node* root)
        {
                if(root==NULL)
                return;
                for(int i=0;i<k;i++)
                {
                cout<<root->point[i]<<" ";
                }
                cout<<endl;
                traverse(root->left);
                traverse(root->right);
        }
// void find_range(Node*root,int x1,int x2,int y1,int y2,int depth)
// {
//     if (root == NULL)
//     {
//                 cout<<"No data available"<<endl;
//     }
//     unsigned cd = depth % k;
//     int low,up;
//     if(cd==0)
//             {    low=x1;
//                  up=x2;
//             }
//     else
//     {    low=y1;
//          up=y2;
//     }
//     if(root->point[0]>=x1 && root->point[0]<=x2 && root->point[1]>=y1 && root->point[1]<=y2)
//            {    
//                cout<<"Point  "<<root->point[0]<<" , "<<root->point[1]<<endl;
//            }
//     if(root->point[cd]>=low && root->point[cd]<=up)
//                     {
//                          if(root->right!=NULL)
//                                 find_range(root->right,x1,x2,y1,y2, depth + 1);
//                          if(root->left!=NULL)
//                                 find_range(root->left,x1,x2,y1,y2, depth + 1);
//     }
//     else if (root->point[cd]<=low )
//                         {if(root->right!=NULL)
//                         find_range(root->right,x1,x2,y1,y2,depth + 1);}
//     else if( root->point[cd]>=up)
//                         {if(root->left!=NULL)
//                         find_range(root->left,x1,x2,y1,y2,depth + 1);}

// }
void find_range(Node*root,int pointst[],int pointe[],int depth)
{
    if (root == NULL)
    {
                cout<<"No data available"<<endl;
    }
    unsigned cd = depth % k;
    int low,up;
    
    low = pointst[cd];
    up = pointe[cd];
//     if(cd==0)
//             {    low=x1;
//                  up=x2;
//             }
//     else
//     {    low=y1;
//          up=y2;
//     }
        int flag=1;
        for(int i=0;i<k;i++)
        {
                if(root->point[i]>=pointst[i]&&root->point[i]<=pointe[i])
                {
                        continue;
                }
                else {
                        flag=0;
                        break;
                }
        }
    if(flag==1)
           {    
               for(int i=0;i<k;i++)
                {
                cout<<root->point[i]<<" ";
                }
                cout<<endl;
           }
    if(root->point[cd]>=low && root->point[cd]<=up)
                    {
                         if(root->right!=NULL)
                                find_range(root->right,pointst,pointe, depth + 1);
                         if(root->left!=NULL)
                                find_range(root->left,pointst,pointe, depth + 1);
    }
    else if (root->point[cd]<=low )
                        {if(root->right!=NULL)
                        find_range(root->right,pointst,pointe,depth + 1);}
    else if( root->point[cd]>=up)
                        {if(root->left!=NULL)
                        find_range(root->left,pointst,pointe,depth + 1);}

}
Node *insertRec(Node *root, int point[], unsigned depth)
{
	if (root == NULL)
            return newNode(point);
	unsigned cd = depth % k;

	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth + 1);
	else
		root->right = insertRec(root->right, point, depth + 1);

	return root;
}
void input()
{
    cout<<endl<<"No of inputs: ";

    FILE* myfile;

    myfile=fopen("input.txt","r");
    int num;
    int point[k];
        fscanf(myfile, "%d", &num);

    for(int i=0;i<num;i++)
    {
            for(int j=0;j<k;j++)
            {
            fscanf(myfile, "%d", &point[j]);
            }
            root = insertRec(root, point, 0);
    }
    
    fclose(myfile);
}

int main()
{
	char c;
        // cout<<"Enter the value of K :"<<endl;
        // cin>>k;
	do{
	cout<<endl<<"1.SEARCH A POINT"<<endl<<"2.RANGE QUERY"<<endl<<"3.INPUT DATA POINTS"<<endl<<"4.Traverse"<<endl;
	int option;
	cin>>option;

    switch(option)
    {
            case 1: int point1[k];
                    cout<<"point to be searched "<<endl;
                    for(int i=0;i<k;i++)
                    {
                            cin>>point1[i];
                    }
                //     cout<<endl<<"x coordinate ";
                //     cin>>point1[0];
                //     cout<<endl<<"y coordinate ";
                //     cin>>point1[1];
                    searchRec(root, point1,0)?cout << "Node Found\n" : cout << "Node not Found\n";
                    break;

            case 2: cout<<endl<<"   RANGE QUERY "<<endl;
                int pointstart[k],pointend[k];
                cout<<"Starting point : ";
                for(int i=0;i<k;i++)
                {
                        cin>>pointstart[i];
                }
                cout<<"Ending Point : ";
                for(int i=0;i<k;i++)
                {
                        cin>>pointend[i];
                }
                //     cout<<"Start of x range :x1  ";
                //     int x1;
                //     cin>>x1;
                //     cout<<"Start of y range :y1 ";
                //     int y1;
                //     cin>>y1;
                //     cout<<"End of x range  :x2  ";
                //     int x2;
                //     cin>>x2;
                //     cout<<"End of y range :y2  ";
                //     int y2;
                //     cin>>y2;
                    
                    find_range(root,pointstart,pointend,0);
                    break;
            case 3: input();
                        // traverse(root);
            case 4: traverse(root);
                    break;
            default:
                    cout<<endl<<"Enter a valid option"<<endl;
    }
    cout<<endl<<"Continue?(y/n)"<<endl;
    cin>>c;
    }
    while(c=='y');
 	return 0;
}
