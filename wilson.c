#include <math.h>
#define PI 3.14159265
 
void put_buf_char(char *buf, float x, float y, char val, int w, int h) {
	buf[(int)(x*(float)w)+(int)(y*(float)h)*(w+1)] = val;
}
 
void draw_line(char *buf, float x1, float y1, float x2, float y2, int w, int h) {
	int divs = 10;
	float dx = (x2 - x1) / (float)divs;
	float dy = (y2 - y1) / (float)divs;
	char c = '?';
	if(fabs(dx) * 2.0 < fabs(dy)) {
		c = '|';
	}else if(fabs(dx) > fabs(dy) * 2.0) {
		c = '-';
	}else if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
		c = '\\';
	}else if((dx > 0 && dy < 0) || (dx < 0 && dy > 0)) {
		c = '/';
	}else {
		c = '?';
	}
 
	for(int i=0; i++ < divs;){
		put_buf_char(buf, x1, y1, c, w, h);
		x1 += dx;
		y1 += dy;
	}
}
 
void draw_ray(char *buf, float x, float y, float rad, float a1, float a2, int w, int h) {
	int divs = 10;
	float v = a1 * 2.0 * PI;
	float dv = (a2 - a1) * 2.0 * PI / (float)divs;
	for(int i = 0; i < divs; i++){
		draw_line(
			buf, 
			rad*cos(v)+x, 
			rad*sin(v)+y, 
			rad*cos(v+dv)+x, 
			rad*sin(v+dv)+y, 
			w, h
		);
		v += dv;
	}
}
 
main(){
	// Create a w*h buffer
	int w,h;
	scanf("%d %d", &w, &h);
	char *buf = malloc(w*h+h);
	int i=0;
	for(int y=0; y<h; y++){
		for(int x=0; x<w; x++)
			buf[i++]=' ';
		buf[i++]='\0';
	}
 
	float n_teeth = 14.0;
	for(float i=0.0; i<n_teeth; i++) {
		draw_ray(buf, 0.5, 0.5, 0.31, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.32, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.33, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.34, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.35, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.36, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.37, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.38, i/n_teeth, 0.01 + i/n_teeth, w, h);
		draw_ray(buf, 0.5, 0.5, 0.39, i/n_teeth, 0.01 + i/n_teeth, w, h);
	}

	// Body
	draw_ray(buf, 0.5, 0.5, 0.3 , 0.0, 1.0, w, h);

	// Shaft hole
	draw_ray(buf, 0.5, 0.5, 0.05, 0.0, 1.0, w, h);

	// Key
	draw_ray(buf, 0.5, 0.5, 0.06 , 0.745, 0.755, w, h);
	draw_ray(buf, 0.5, 0.5, 0.07, 0.745, 0.755, w, h);

	// Eyes
	draw_ray(buf, 0.4, 0.4, 0.025, 0.0, 1.0, w, h);
	draw_ray(buf, 0.6, 0.4, 0.025, 0.0, 1.0, w, h);

	// Mouth
	draw_ray(buf, 0.5, 0.5, 0.15, 0.1, 0.4, w, h);
	draw_ray(buf, 0.5, 0.5, 0.16, 0.1, 0.4, w, h);
	draw_ray(buf, 0.5, 0.5, 0.17, 0.1, 0.4, w, h);
	draw_ray(buf, 0.5, 0.5, 0.18, 0.1, 0.4, w, h);
 
	// Print wilson
	for(int y=0; y<h; y++){
		printf("%s\n",&buf[y*(w+1)]);
	}
}
