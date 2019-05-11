import constantes as CONST

class Jugador:
	def __init__(self,nombre,nivel,goles,sueldo,bono,sueldo_completo,equipo):
		self.nombre = nombre
		self.nivel = nivel
		self.goles = goles
		self.sueldo = sueldo
		self.bono = bono
		self.sueldo_completo = sueldo_completo
		self.equipo = equipo
		self.goles_meta = CONST.CATALOGO_NIVEL[nivel]
	
	def bono_meta_individual(self):
		if self.goles > self.goles_meta:
			return 0.5
		return 0.5*(self.goles/self.goles_meta)

	def ToJSON(self):
		data = {}
		data["nombre"] = self.nombre
		data["nivel"] = self.nivel
		data["goles"] = self.goles
		data["sueldo"] = self.sueldo
		data["bono"] = self.bono
		data["sueldo_completo"] = self.sueldo_completo
		data["equipo"] = self.equipo
		return data
