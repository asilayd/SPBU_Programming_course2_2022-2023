#include <iostream>
#include <fstream>

using namespace std;

class Command {
public:
	virtual ~Command() {
	}
	virtual void Execute() const =0 {};
};

class Write_Command : public Command {
	string text;
	string name;
public:
	Write_Command(string txt, string n): text(txt), name(n){}
	void Execute() const override
	{
		ofstream out;
		out.open(name);
		out << text;
		out.close();
	}
};

class Invoker {

	Command* cmd;
public:
	Invoker(Command* cmd): cmd(cmd){}
	~Invoker() { delete cmd; }
	void DoWork()
	{
		this->cmd->Execute();
	}
};

int main()
{
	string name;
	string text;
	cout << "Type file name to write in: .... ";
	cin >> name;
	cout << "Type the text to write it in " << name << " :";
	cin >> text;
	Command* command = new Write_Command(text, name);
	Invoker* invoker = new Invoker(command);
	invoker->DoWork();
	cout << endl;



	return 0;
}