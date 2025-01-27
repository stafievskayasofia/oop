#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Rectangle
{
    int x;
    int y;
    int width;
    int height;
    string fill;
};

struct Polygon
{
    vector<pair<int, int>> points;
    string fill;
};

struct Circle
{
    int cx;
    int cy;
    int r;
    string fill;
};


// Процедура записи прямоугольников
ostream& operator<<(ostream& os, const Rectangle& rect)
{
    return os << "<rect x=\"" << rect.x << "\" y=\"" << rect.y
        << "\" width=\"" << rect.width
        << "\" height=\"" << rect.height
       
        << "\" fill=\"" << rect.fill << "\" />";
}

// Процедура записи многоугольников
ostream& operator<<(ostream& os, const Polygon& poly)
{
    os << "<polygon points=\"";

    for (const auto& point : poly.points)
    {
        os << point.first << "," << point.second << " ";
    }

    os << "\" fill=\"" << poly.fill << "\""
      
        << " />";

    return os;
}

ostream& operator<<(ostream& os, const Circle& circle)
{
    return os << "<circle cx=\"" << circle.cx << "\" cy=\"" << circle.cy
        << "\" r=\"" << circle.r << "\" fill=\"" << circle.fill << "\" />";
}




int main() {
    setlocale(LC_ALL, "ru");
    ofstream fout("result_SVG_picture.svg");

    fout << "<svg width=\"620px\" height=\"440px\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n"; 

    fout << Rectangle{ 0, 0, 620, 440, "#ADA992" } << endl;
    fout << Rectangle{ 450, 190, 168, 100, "#293022" } << endl;
    fout << Circle{ 211, 275, 119, "#AF9257" } << endl;
    fout << Polygon{ {{4, 40}, {124, 391}, {330, 202}}, "#ADA992" } << endl;
    fout << Rectangle{ 104, 194, 168, 100, "#1F1917" } << endl;
    fout << Rectangle{ 39, 229, 217, 100, "#4A2C22" } << endl;
    fout << Rectangle{ 226, 73, 256, 241, "#1D1A1D" } << endl;
    fout << Polygon{ {{226, 74}, {482, 74}, {482, 57}}, "#1D1A1D" } << endl;
    fout << Rectangle{ 277, 168, 100, 134, "#504D40" } << endl;
    fout << Rectangle{ 356, 205, 46, 70, "#81382A" } << endl;
    fout << Rectangle{ 467, 319, 108, 11, "#342D27" } << endl;
    fout << Rectangle{ 340, 247, 162, 109, "#9C5C2A" } << endl;
    fout << Polygon{ {{374, 146}, {381, 153}, {442, 97}, {436, 91}}, "#72733D" } << endl;
    fout << Circle{ 275, 227, 65, "#B4AD9A" } << endl;
    fout << "</svg>\n";
    fout.close();
    return 0;
}