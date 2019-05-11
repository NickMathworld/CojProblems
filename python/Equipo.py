import Jugador

class Equipo:
	def __init__(self,equipo_nombre):
		self.equipo_nombre = equipo_nombre
		self.jugadores = []
		self.goles_totales = 0
		self.goles_equipo_meta = 0

	def agrega_jugador(self,player):
		self.jugadores.append(player)
		self.goles_totales += player.goles
		self.goles_equipo_meta += player.goles_meta

	def bono_meta_equipo(self):
		if self.goles_totales > self.goles_equipo_meta:
			return 0.5
		return 0.5*(self.goles_totales/self.goles_equipo_meta)

	def actualiza_sueldos(self):
		for jugador in self.jugadores:
			jugador.sueldo_completo = round(jugador.sueldo+(self.bono_meta_equipo()+jugador.bono_meta_individual())*jugador.bono,2)