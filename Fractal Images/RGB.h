/*
 * RGB.h
 *
 *  Created on: Sep 21, 2015
 *      Author: johnpurcell
 */

#ifndef RGB_H_
#define RGB_H_

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
};

RGB operator-(const RGB& first, const RGB& second);




#endif /* RGB_H_ */
