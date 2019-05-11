import json
import Jugador
import Liga
import ValidadorJSON
import constantes as CONST
def crea_jugador(data):
	"""
		Función para generar una instancia de un jugador dada la información de un diccionario
	"""
	return Jugador.Jugador(data["nombre"],data["nivel"],data["goles"],data["sueldo"],data["bono"],data["sueldo_completo"],data["equipo"])

def calcula_sueldos(entrada):
	"""
    Calcula los sueldos completos de los jugadores de los equipos.
    
    >>> calcula_sueldos("data_in")
    200
    >>> calcula_sueldos("data_error")
    400
    >>> calcula_sueldos("data_error_noexiste")
    500
    """
	validador = ValidadorJSON.ValidadorJSON()
	data_in = validador.cargaJSON(entrada)
	data_out = []
	if data_in == CONST.ERROR_FORMATO or data_in == CONST.ERROR_JSON:
		return data_in

	liga = Liga.Liga()
	for it in data_in:
		liga.agrega_jugador(crea_jugador(it))

	for equipo in liga.equipos.values():
		equipo.actualiza_sueldos()
	
	for equipo in liga.equipos.values():
		for jugador in equipo.jugadores:
			data_out.append(jugador.ToJSON())

	validador.exportaJSON(entrada,data_out)
	return 200
if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)
    calcula_sueldos("data_test")