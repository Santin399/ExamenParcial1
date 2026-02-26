#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>

std::mutex mtx;

void escribirLinea(int id) {
    std::string texto = "thread #" + std::to_string(id);
    std::lock_guard<std::mutex> lock(mtx);
    std::ofstream archivo("salida.txt", std::ios::app);
    if (archivo.is_open()) archivo << texto << "\n";
}

int main() {
    std::ofstream("salida.txt", std::ios::trunc);

    std::thread t1(escribirLinea, 1);
    std::thread t2(escribirLinea, 2);
    std::thread t3(escribirLinea, 3);
    std::thread t4(escribirLinea, 4);
    std::thread t5(escribirLinea, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "Listo.\n";
    return 0;
}