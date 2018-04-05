	//
	//  main.cpp
	//  Factorial Images
	//
	//  Created by Stefanos Mitropoulos on 05/04/2018.
	//  Copyright © 2018 Stefanos Mitropoulos. All rights reserved.
	//
#include "Bitmap.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
	int const WIDTH=20000;
	int const HEIGHT=20000;

	caveofprogramming::Bitmap bitmap(WIDTH,HEIGHT);

	double min=999999;
	double max=-999999;

	std::unique_ptr<int[]> histogram(new int[caveofprogramming::Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[HEIGHT*WIDTH]{0});

	for (int y=0;y<HEIGHT;y++){
		for (int x=0;x<WIDTH;x++){

			double xFractal = (x -200 - WIDTH/2) * 2.0/WIDTH;
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
			
			int iterations = caveofprogramming::Mandelbrot::getIterations(xFractal, yFractal);
			fractal[y*WIDTH + x] = iterations;


			if(iterations!=caveofprogramming::Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}



		}
	}

	int total = 0;

	for (int i=0;i<caveofprogramming::Mandelbrot::MAX_ITERATIONS;i++){
		total+=histogram[i];
	}

	for (int y=0;y<HEIGHT;y++){
		for (int x=0;x<WIDTH;x++){

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			int iterations = fractal[y*WIDTH + x];

			double hue=0.0;

			if (iterations!=caveofprogramming::Mandelbrot::MAX_ITERATIONS){
				for (int i=0; i<=iterations; i++){
					hue += ((double)histogram[i])/total;
				}
			}

			red=0;
			green=pow(255,hue);
			blue=0;

			bitmap.setPixel(x, y, red,green,blue);


		}

	}

	bitmap.write("test.bmp");
	
	std::cout << "Finished\n";
	return 0;
}
