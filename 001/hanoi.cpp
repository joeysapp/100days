#include <iostream>
#include <fstream>
#include <ctime>
#include <stack>
#include "Tower.cpp"

using namespace std;

int moves_made = 0;
Tower t1, t2, t3;

void movePiece(int node_count, Tower* t_t1, Tower* t_t2, Tower* t_t3){
	if (node_count <= 0){
		t_t2->addNode(t_t1->removeNode());
	} else {
		movePiece(node_count-1, t_t1, t_t3, t_t2);
		t_t2->addNode(t_t1->removeNode());
		movePiece(node_count-1, t_t3, t_t2, t_t1);
	}
	moves_made++;
}

void printTowers(){
	std::cout << "[ Tower 1 ] : " << t1.getSize() << std::endl;
	std::cout << "[ Tower 2 ] : " << t2.getSize() << std::endl;
	std::cout << "[ Tower 3 ] : " << t3.getSize() << std::endl << std::endl;
}

int main(int argc, char *argv[]){

	std::ofstream csv_file("times.csv", ios::app);
	
	int num_of_disks = atoi(argv[1]);
	std::cout << "Your tower will be " << num_of_disks << " disks tall." << std::endl;
	
	for (int i = 0; i < num_of_disks; i++){
		t1.addNode(Node(i));		
	}

	printTowers();
	std::clock_t start = std::clock(); 
	movePiece(num_of_disks-1, &t1, &t3, &t2);
	printTowers();
	
	std::cout << "Moves made: " << moves_made << std::endl;
	std::string type_of_time = " ms";
	double time = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1);
	
	std::cout << "Time: " << time << type_of_time << std::endl;
	csv_file << num_of_disks << ", " << moves_made << "," << time << "\n";
	csv_file.close();
	
}





