from KB_deportes import kb_deportes

# Función para hacer el backward chaining con preguntas de sí/no
def backward_chaining(kb, goal):
    # Iterar sobre las reglas de la base de conocimiento
    goal = goal.lower().strip()  # Normalizar el valor de la meta
    for regla in kb:
        if regla["then"]["variable"] == "deporte" and regla["then"]["value"].lower() == goal:
            print(f"Probando meta: {goal} con la regla: {regla['rule_name']}")
            
            # Revisar todas las condiciones de la regla
            todas_condiciones_cumplidas = True
            for condicion in regla["if"]:
                variable = condicion["variable"]
                valor_esperado = condicion["value"].lower().strip()  # Normalizar también el valor esperado
                  
                # Preguntar solo si no tenemos este dato en inputs
                if variable not in inputs or inputs[variable] == "":
                    respuesta = input(f"¿El valor de {variable} es {valor_esperado}? (si/no): ").strip().lower()
                    
                    # Convertir la respuesta en el valor booleano correcto
                    if respuesta == "si":
                        inputs[variable] = valor_esperado
                    else:
                        inputs[variable] = "no"
                
                # Verificar si la respuesta coincide con el valor esperado
                if inputs[variable] != valor_esperado:
                    print(f"Condición fallida: {variable} != {valor_esperado}")
                    todas_condiciones_cumplidas = False
                    break
            
            # Si todas las condiciones se cumplen, entonces se confirma la meta
            if todas_condiciones_cumplidas:
                return f"El deporte es: {goal}"

    return "No se puede determinar el deporte con los datos proporcionados."


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

# Recibir inputs del usuario
def obtener_datos_usuario():
    
    inputs_user["num_jugadores"] = int(input("¿Cuántos jugadores tiene tu deporte? "))
    inputs_user["balon"] = input("¿Se usa un balón? (si/no) ")
    inputs_user["tipo_cancha"] = input("¿Qué forma tiene la cancha? (rectangular/diamante) ")
    inputs_user["cancha"] = input("¿Cuál es la superficie? (superficie dura/cesped/hielo/arena/mesa) ")

    cond1 = input("¿Se usa algún equipamiento? (si/no) ")
    if cond1 == "si":
        inputs_user["equipo"] = input("¿Cuál? ")
    else:
        inputs_user["equipo"] = "ninguno"    
        return inputs_user

# Main: ejecutar el sistema experto con backward chaining o forward chaining

tipo="deporte"


def sistema_experto_deportes():
    print("Sistema Experto de Deportes")

    elect = input("¿Qué deseas hacer, inferencia por forward o backward chaining? (1 para backward, 2 para forward): ")
    while elect not in ["1", "2"]:
        elect = input("Por favor elige una opción válida (1 para backward, 2 para forward): ")

    if elect == "1":
        goal = input("¿Cuál es el deporte meta que quieres verificar? ")  # Meta = nombre del deporte
        resultado = backward_chaining(kb_deportes, goal)
        print(resultado)
    else:
        inputs_user = obtener_datos_usuario()  # Aquí pedimos los datos al usuario
        resultado = adiv_deport(kb_deportes, inputs_user)
        print(f"El deporte es {resultado}")

# Ejecutar el sistema
sistema_experto_deportes()
