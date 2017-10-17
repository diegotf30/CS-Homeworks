#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
	protected:

    private:
        double dRadius;

    public:
    	//Constructors
        Circle(double dRadius);
        Circle();
        //Setter
        void setRadius(double dRadius);
        //Getter
        double getRadius();
        //Methods
        double calcArea();
        double calcPerimeter();

       /*Destructor */ virtual ~Circle();

};

#endif // CIRCLE_H
