
#ifndef MRT_TOURIST_HPP
#define MRT_TOURIST_HPP
#include <string>

using namespace std;
class Tourist {
 public:
  Tourist() {}

  virtual ~Tourist();
 public:
  /**
   * @brief @param start: Punto de inicio
   *        @param days: Días  de estancia
   *        @param preferences: Distancia - Estrellas
   *        @param duration: Duracion de la ruta en minutos
   *        @param cirudlar: Recorrido circular o lineal
   */
  static int start, days, preferences, time, circular;
 public:
  static void setParams(const int startPoint, const int numDays, const int pref, const int duration, const int cir);
  static string toString();
 public:
  static const int CIRCULAR;
  static const int LINEAL;
  static const int DISTANCE;
  static const int RATE;
};
#endif //MRT_TOURIST_HPP