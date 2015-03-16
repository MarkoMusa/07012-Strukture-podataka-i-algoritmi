class Rectangle 
{
private:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double width, double height);

	void set(double width, double height);
	void set(double side);

	double getWidth();
	double getHeight();
	double getArea();
};