import json

catalogo_nivel = {"A":5,"B":10,"C":15,"Cuauh":20}

class Jugador:
	def __init__(self,nombre,nivel,goles,sueldo,bono,sueldo_completo,equipo):
		self.nombre = nombre
		self.nivel = nivel
		self.goles = goles
		self.sueldo = sueldo
		self.bono = bono
		self.sueldo_completo = sueldo_completo
		self.equipo = equipo
		self.goles_meta = catalogo_nivel[nivel]
	
	def bono_meta_individual(self):
		if self.goles > self.goles_meta:
			return 0.5
		return 0.5*(self.goles/self.goles_meta)

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

	def calcula_sueldos(self):
		for jugador in self.jugadores:
			jugador.sueldo_completo = jugador.sueldo+(self.bono_meta_equipo()+jugador.bono_meta_individual())*jugador.bono
			print(jugador.nombre)
			print("Goles :"+str(jugador.goles))
			print("Goles nivel: "+str(jugador.goles_meta))
			print("Tasa de bono: "+ str(self.bono_meta_equipo()+jugador.bono_meta_individual()))
			print("Sueldo total: "+str(jugador.sueldo_completo)+"\n")

class Liga:
	def __init__(self):
		self.equipos = {}

	def agrega_jugador(self,player):
		aux_equipo = player.equipo
		# No existe aún el equipo
		if aux_equipo not in self.equipos:
			self.equipos[aux_equipo] = Equipo(aux_equipo)
		self.equipos[aux_equipo].agrega_jugador(player)


def crea_jugador(data):
	return Jugador(data["nombre"],data["nivel"],data["goles"],data["sueldo"],data["bono"],data["sueldo_completo"],data["equipo"])

def cargaJSON():
	data = {}
	try:
		with open('data.json') as json_file:
			data = json.load(json_file)
		return data
	except:
		print("Error al leer archivo JSON")
def validaJSON(data):
	

def main():
    data = cargajson()
    liga = Liga()
    # Python Object
    for it in data:
    	liga.agrega_jugador(crea_jugador(it))

    for equipo in liga.equipos.values():
    	print("Equipo:"+equipo.equipo_nombre)
    	print("Goles totales: "+str(equipo.goles_totales))
    	print("Goles Meta: "+str(equipo.goles_equipo_meta)+"\n")
    	equipo.calcula_sueldos()

if __name__ == "__main__":
    main()