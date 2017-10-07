#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
	public:
		///Default Constructor
		Triangle();
		///Constructor
		Triangle(double dBase, double dHeight);

		///Destructor
		virtual ~Triangle();

        ///Methods
        double calcPerimeter();
        double calcArea();

	protected:

	private:
		double dBase;
		double dHeight;
};

#endif // TRIANGLE_H
