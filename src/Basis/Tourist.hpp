
#ifndef MRT_TOURIST_HPP
#define MRT_TOURIST_HPP
#include <string>

using namespace std;
class Tourist {
 public:
	Tourist();
	Tourist(int& startPoint, int& days, int& preferences, int& time, int& circular);
	virtual ~Tourist();
 private:
	/**
	 * @brief @param start: Punto de inicio
	 *        @param days: Días  de estancia
	 *        @param preferences: Distancia - Estrellas
	 *        @param duration: Duracion de la ruta en minutos
	 *        @param cirudlar: Recorrido circular o lineal
	 */
	int start, days, preferences, time, circular;
 public:
	void setStartPoint(const int&);
	void setDays(const int&);
	void setPreferences(const int&);
	void setTime(const int&);
	void setCircular(const int&);
	int getStartPoint();
	int getDays();
	int getPreferences();
	int getTime();
	int getCircular();
 public:
	string toString();
 public:
	static const int CIRCULAR;
	static const int LINEAL;
	static const int DISTANCE;
	static const int RATE;
};
#endif //MRT_TOURIST_HPP