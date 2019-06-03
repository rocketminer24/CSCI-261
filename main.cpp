/* CSCI 261 A2: Triangles
 *
 * Author: Jarod Spencer
 *
 * Description: Calculating things about triangles based on user inputs.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

    //establishes x & y coordinate variables
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

    //user inputs x & y coordinates
    cout << "\nEnter the coordinates of the first vertex: ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second vertex: ";
    cin >> x2 >> y2;

    cout << "Enter the coordinates of the third vertex: ";
    cin >> x3 >> y3;
    cout << endl;

    //computer calculates and prints side lengths
    double s1 = sqrt (pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
    double s2 = sqrt (pow((x3 - x1), 2.0) + pow((y3 - y1), 2.0));
    double s3 = sqrt (pow((x3 - x2), 2.0) + pow((y3 - y2), 2.0));

    cout << fixed << setprecision (3) << "The side lengths are: ";
    cout << s1 << " " << s2 << " " << s3 << endl;

    /*computer determines if the sides makes a triangle and, if so, calculates and
     * prints the perimeter and area values
     */
    if (s1 < (s2 + s3) and s2 < (s1 + s3) and s3 < (s1 + s2))     {
        cout << "These sides do form a triangle.\n" << endl;
        double perimeter = s1 + s2 + s3;
        double S = (s1 + s2 + s3)/2;
        double area = sqrt (S * (S - s1) * (S - s2) * (S - s3));
        cout << "The perimeter is: " << fixed << perimeter << endl;
        cout << "The area is: " << fixed << area << endl;
    } else {
        cout << "These sides do not form a triangle. Have a nice day." << endl;
    }

    return 0;
}