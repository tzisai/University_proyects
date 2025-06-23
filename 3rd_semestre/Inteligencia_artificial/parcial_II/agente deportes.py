from KB_deportes import kb_deportes

def adiv_deport(kb, inputs):
    for regla in kb:
        cond = True

        for condicion in regla["if"]:
            variable = condicion["variable"]
            valor = condicion["value"]

            if variable in inputs and inputs[variable] != "":
                if str(inputs.get(variable)) != str(valor):  # Convertir a cadena para comparar
                    cond = False
                    break  

        if cond:
            return regla["then"]["value"]

    return "NO se tu deporte"

inputs_user = {
    "num_jugadores": "0", 
    "balon": "",
    "cancha": "",
    "tipo_cancha": "",
    "equipo": ""  
}

print("Forward Chaining")
print("Responde las siguientes preguntas")

# Cambiar a enteros y preguntar correctamente por los atributos
inputs_user["num_jugadores"] = int(input("¿Cuántos jugadores tiene tu deporte? "))
inputs_user["balon"] = input("¿Se usa un balón? (si/no) ")
inputs_user["tipo_cancha"] = input("¿Qué forma tiene la cancha? (rectangular/diamante) ")
inputs_user["cancha"] = input("¿Cuál es la superficie? (superficie dura/cesped/hielo/arena/mesa) ")

cond1 = input("¿Se usa algún equipamiento? (si/no) ")
if cond1 == "si":
    inputs_user["equipo"] = input("¿Cuál? ")

deporte = adiv_deport(kb_deportes, inputs_user)
print(f"El deporte es: {deporte}")
