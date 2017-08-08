// https://math.stackexchange.com/questions/1835412/fsm-to-add-two-integer
#include <iostream>
#include <bitset>
#include <string>

// https://stackoverflow.com/questions/7663709/convert-string-to-int-c
unsigned binary_to_decimal(unsigned num){
	unsigned res = 0;
	for (int i = 0; num > 0; ++i){
		if ((num % 10) == 1){
			res += (1 << i);
		}
		num /= 10;
	}
	return res;
}

class finite_state_machine {
	public:
	int states[2] = { 0, 1 };
	int state = 0;
	std::string n1, n2;

	finite_state_machine(std::string t_n1, std::string t_n2){
		if (t_n1.length() == t_n2.length()){
			n1 = t_n1;
			n2 = t_n2;
		} else {
			std::cout << "There was an error." << std::endl;
		}
	}

	int add(){
		std::string result;
		for (int i = 0; i < n1.length(); i++){
			if (state == 0){
				if (n1[i] == '0' && n2[i] == '0'){
					result.append("0");
				} else if ((n1[i] == '0' && n2[i] == '1') ||
					   (n1[i] == '1' && n2[i] == '0')){
					result.append("1");
				} else if (n1[i] == '1' && n2[i] == '1'){
					result.append("0");
					state = 1;
				}
			} else if (state == 1){
				if (n1[i] == '0' && n2[i] == '0'){
					result.append("1");
					state = 0;
				} else if ((n1[i] == '0' && n2[i] == '1') ||
					   (n1[i] == '1' && n2[i] == '0')){
					result.append("0");
				} else if (n1[i] == '1' && n2[i] == '1'){
					result.append("1");
				}
			}
		}
		std::reverse(result.begin(), result.end());
		return stoi(result);
	}
};

int main(int argc, char *argv[]){
	int num_1 = atoi(argv[1]);
	int num_2 = atoi(argv[2]);

	std::string s_num_1 = std::bitset<16>(num_1).to_string();
	std::string s_num_2 = std::bitset<16>(num_2).to_string();

	std::reverse(s_num_1.begin(), s_num_1.end());
	std::reverse(s_num_2.begin(), s_num_2.end());

	finite_state_machine fsm(s_num_1, s_num_2);
	
	std::cout << binary_to_decimal(fsm.add()) << std::endl;
}
