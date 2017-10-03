#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
	///Attributes
	private:
		double dBase;
		double dHeight;

	///Methods
	public:
		///Constructors
		Rectangle(double dBase, double dHeight);
		Rectangle();

		///Destructor
		virtual ~Rectangle();

		//Setters and Getters
		void setBase(double dBase);
		void setHeight(double dHeight);
		double getBase();
		double getHeight();

		///Class Functions
		double calcArea();
		double calcPerimeter();
		void draw();
};

#endif // RECTANGLE_H
