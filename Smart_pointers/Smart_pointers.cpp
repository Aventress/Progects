#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
	int data;
public:
	Test() :data{0}{ std::cout << "base Test constructor called \n"; }
	Test(int data) :data{ data } { std::cout << "Test constructor with data " << data << std::endl; }
	int get_data() const { return data; }
	~Test() { std::cout << "destructor called for " << data << std::endl; }
};

auto make() {
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
	return ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, size_t num) {
	int data{};
	size_t i{};
	std::cout << "==========================================\n";
	for (i; i < num; ++i) {
		std::cout << "\nEnter a number for data in [" << i << "] place: ";
		std::cin >> data;
		vec.push_back(std::make_shared<Test>(data));
	}
}

void display(const std::vector<std::shared_ptr<Test>>&vec) {
	size_t counter{};
	std::cout << "==========================================\n";
	for (const auto vec_dis : vec) {
		std::cout << "Data at segment [" << counter <<"]: " << vec_dis->get_data() << std::endl;
		counter++;
	}
	std::cout << "==========================================\n";
}

int main() {
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	size_t num{};
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);
	return 0;
}