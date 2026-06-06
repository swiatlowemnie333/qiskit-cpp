#ifndef BBB_HPP
#define BBB_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <regex>

class QuantumCircuit;

namespace bbb {
    // Prosta, chamska funkcja zamieniająca pythonowe a**b na pow(a,b)
    inline std::string sanitize_param(std::string expr) {
        std::regex pow_regex("([a-zA-Z0-9_\\.]+)\\s*\\*\\*\\s*([a-zA-Z0-9_\\.]+)");
        while (std::regex_search(expr, pow_regex)) {
            expr = std::regex_replace(expr, pow_regex, "pow($1, $2)");
        }
        return expr;
    }

    inline std::string export_to_qasm3(const QuantumCircuit& circuit) {
        std::stringstream qasm3;
        qasm3 << std::setprecision(18);
        qasm3 << "OPENQASM 3.0;\n";
        qasm3 << "include \"stdgates.inc\";\n";
        // Tu potem wrzucimy resztę prostej pętli
        return qasm3.str();
    }
}

#endif // BBB_HPP
