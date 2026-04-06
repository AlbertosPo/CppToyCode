#include <iostream>
#include <string>




class Triangle
{
private:
	int base;
	bool valid = false;

public:
	Triangle(int base_in) {
        base = base_in;
	}

	bool ReturnValid(int CheckBase)
	{
		if (CheckBase >= 3 && 100 > CheckBase){
			// std::cout << "Valid" << std::endl;
			return true;
		}			
		else
		{
			// std::cout << "Not-Valid" << std::endl;
			return false;
		}
		 std::cout << std::endl;
	}

	void PrintingStars(int howManyStars,int spaces_in, bool allow_in=false)
	{

		if (allow_in == true && howManyStars == 1)
		{
			
		}
		else 
		{
			for (int i = 0; i < spaces_in; i++)
			{
				std::cout << " ";
			}
			for (int i = 0; i < howManyStars; i++)
			{
				std::cout << "*";
				if (i + 1 < howManyStars)
					std::cout << " ";
			}
			std::cout << std::endl;
		}
			
	}

	void PrintingStars_right(int stars_in)
	{
		for (int i = 0; i < stars_in; i++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	void PrintingStars_left(int spaces_in,int stars_in)
	{
		for (int i = 0; i < spaces_in; i++)
		{
			std::cout << " ";
		}

		for (int i = 0; i <= stars_in; i++)
		{
			std::cout << "*";
		}
		std::cout <<  std::endl;
	}


	void UpsideDownPrintTriangle(bool avoid = false)
	{
		// std::cout << "Down - Triangle" << std::endl;
		if (ReturnValid(base) == true )
		{
			int countSpaces = 0;
			for (int i = base; i > 0; i=i-1)
			{
				if (avoid == true && i == base)
				{
					
					countSpaces++;
					avoid = false;
					continue;
				}
				else {
					
					PrintingStars(i, countSpaces, avoid);
					countSpaces++;
				}
			}
			//std::cout << std::endl;
		}
	}


	void NormalPrintTriangle(bool avoid = false)
	{
		// std::cout << "Up - Triangle" <<std::endl;
		if (ReturnValid(base) == true)
		{
			int countSpaces = base;
			for (int i = 0; i <= base; i = i + 1)
			{
				if (avoid == true && i==0 )
				{
					i++;
					countSpaces = countSpaces - 2;
					avoid = false;
					continue;
				}
				else {
					PrintingStars(i, countSpaces);
					countSpaces--;
				}
			}
			
		}
	}

	void RightPrintTriangle()
	{
		// std::cout << "Right - Triangle" << std::endl;
		int depth = base * 2 - 1;
		if (ReturnValid(base) == true)
		{

			for (int i = 0; i <= depth; i++)
			{
				if (i <= base)
				{
					PrintingStars_right(i);
				}
				else if (i>base)
				{
					PrintingStars_right(depth - (i - 1) );
				}
			}
		}
	}

	void LeftPrintTriangle()
	{
		// std::cout << "Left - Triangle" << std::endl;
		int depth = base * 2 - 1;
		if (ReturnValid(base) == true)
		{
			int countStars = 0;
			for (int i = depth; i > 0; i--)
			{
				if (i > base)
				{
					PrintingStars_left(i,countStars);
				}
				else if (i <= base)
				{
					PrintingStars_left(depth - (i - 1) , depth - (countStars+1) );
				}
				countStars++;
			}
		}
	}

};


int InputGetter()
{
	int inputGet;
	std::cin >> inputGet;
	return inputGet;
}


void ShowSomeTriangle(Triangle obj_in, std::string which)
{
	if (which == "up")
	{
		obj_in.NormalPrintTriangle();
	}
	else if (which == "down")
	{
		obj_in.UpsideDownPrintTriangle();
	}
	else if (which == "right")
	{
		obj_in.RightPrintTriangle();
	}
	else if (which == "left")
	{
		obj_in.LeftPrintTriangle();
	}
	else if (which == "combUpDown")
	{
		obj_in.NormalPrintTriangle();
		obj_in.UpsideDownPrintTriangle(true);
	}
	else if (which == "combDownUp")
	{
		obj_in.UpsideDownPrintTriangle();
		obj_in.NormalPrintTriangle(true);
	}

}


int main()
{	
	int input;
	bool goOn = true;
	std::string choice = " ";
	input = InputGetter();


	Triangle Obj(input);
	
	while (goOn)
	{
		std::cout << "Your chooses are " << std::endl;
		std::cout << "1) up" << std::endl;
		std::cout << "2) down" << std::endl;
		std::cout << "3) right" << std::endl;
		std::cout << "4) left" << std::endl;
		std::cout << "5) combUpDown" << std::endl;
		std::cout << "6) combDownUp" << std::endl;
		std::cout << "To Exit type exit" << std::endl;
		std::cin >> choice;

		if (choice == "exit")
		{
			goOn = false;
		}
		ShowSomeTriangle(Obj, choice);
	}


	return 0;
}






