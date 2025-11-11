#include <iostream>
#include "json.hpp" // nlohmann::json

using json = nlohmann::json;

int main() {
    // Creamos un JSON en línea
    json user = {
        {"name", "Raul"},
        {"age", 40},
        {"languages", {"C++", "Python", "Rust"}}
    };

    // Lo mostramos bonito
    std::cout << "Usuario: " << user.dump(4) << std::endl;

    // Parseamos desde string
    std::string s = R"({"msg": "Hola Docker", "ok": true})";
    json parsed = json::parse(s);
    std::cout << "Mensaje: " << parsed["msg"] << std::endl;

    return 0;
}
