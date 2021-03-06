#include"vector3.h"

int main() {
    Vector3 vec1(5, 4, 3);
    Vector3 vec(1, 0, 0);
    Vector3 axis(0, 1, 0);
    float alpha = 90;
    vec1.print();
    /* check len() and squareLen() methods */
    std::cout << "getting vector's length = " << vec1.len() << "\n";
    std::cout << "getting square length = " << vec1.squareLen() << "\n";
    Vector3 vec2(vec1);
    
    /*check overloaded operators*/
    std::cout << "Please, write coordinates of new vector\n";
    std::cin >> vec;
    std::cout << "sum of vectors: " << vec1 + vec2 << "\n";
    std::cout << "sub of vectors: " << vec1 - vec2 << "\n";
    std::cout << "sum of vectors(write in vec2): " << (vec2 += vec1) << "\n";
    std::cout << "sub of vectors(write in vec2): " << (vec2 -= vec1) << "\n";
    std::cout << "normalize vec2: " << vec2.norm() << "\n";
    std::cout << "getting normal to vec2: " << vec2.get_normal() << "\n";
    std::cout << "get new rotated vector(rotate copy of vec): " << vec.get_rotated(axis, 90) << "\n"; 
    std::cout << "rotate vec: " << vec.rotate(axis, 90) << "\n";
    std::cout << "vector mult: " << (vec ^ vec.get_normal()) << "\n";
    std::cout << "scaler mult: " << (axis * vec1) << "\n";
    std::cout << "div on scaler: " << (vec1 /= 5) << "\n";
    std::cout << "mult on scaler(1): " << (vec *= 5) << "\n";
    std::cout << "mult on scaler(2): " << (5 *= vec) << "\n";
    std::cout << "unary minus: " << -vec;
}
    

