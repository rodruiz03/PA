#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>

class Publicacion {
public:
    int getId() const;
    std::string getTitulo() const;
    std::string getMateria() const;
    int getEjemplares() const;
    bool estaDisponible() const;
    float calcularMulta(int diasRetraso);

    char ingresarPublicacion(char tipoPublicacion);

    Publicacion() {}
    Publicacion(int id, std::string titulo, std::string materia, int ejemplares, bool disponible) {
        this->id = id;
        this->titulo = titulo;
        this->materia = materia;
        this->ejemplares = ejemplares;
        this->disponible = disponible;
    }
    virtual ~Publicacion();

    
    
protected:
    int id;
    std::string titulo;
    std::string materia;
    int ejemplares;
    bool disponible;
};

#endif
