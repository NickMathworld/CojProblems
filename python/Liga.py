import Jugador
import Equipo

class Liga:
	def __init__(self):
		self.equipos = {}

	def agrega_jugador(self,player):
		aux_equipo = player.equipo
		# No existe aún el equipo
		if aux_equipo not in self.equipos:
			self.equipos[aux_equipo] = Equipo.Equipo(aux_equipo)
		self.equipos[aux_equipo].agrega_jugador(player)