import tkinter as tk
from tkinter import ttk, messagebox, simpledialog

# Bases de conocimiento
from KB_deportes import kb_deportes
from KB_vehiculos import kb_vehiculos

# Función de Forward chaining adaptada
def forward_chaining(kb, inputs):
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
    
    return "No se encontró un resultado"

# Función que pide las entradas y llama a forward_chaining
def ask_forward_inputs(kb):
    inputs_user = {
        "num_jugadores": simpledialog.askinteger("Pregunta", "¿Cuántos jugadores tiene tu deporte?"),
        "balon": simpledialog.askstring("Pregunta", "¿Se usa un balón? (si/no)"),
        "tipo_cancha": simpledialog.askstring("Pregunta", "¿Qué forma tiene la cancha? (rectangular/diamante)"),
        "cancha": simpledialog.askstring("Pregunta", "¿Cuál es la superficie? (superficie dura/cesped/hielo/arena/mesa)")
    }
    
    cond1 = simpledialog.askstring("Pregunta", "¿Se usa algún equipamiento? (si/no)")
    if cond1 == "si":
        inputs_user["equipo"] = simpledialog.askstring("Pregunta", "¿Cuál equipamiento?")
    else:
        inputs_user["equipo"] = ""
    
    deporte = forward_chaining(kb, inputs_user)
    messagebox.showinfo("Resultado", f"El deporte es: {deporte}")

# Función de Backward chaining
def backward_chaining(kb, goal):
    applicable_rules = []
    for rule in kb:
        if rule['then']['value'].lower() == goal.lower():
            applicable_rules.append(rule)
    if applicable_rules:
        result = "\n".join([f"Regla {rule['rule_name']}: IF {rule['if']} THEN {rule['then']}" for rule in applicable_rules])
        messagebox.showinfo("Reglas aplicables", result)
    else:
        messagebox.showinfo("Error", "No se encontraron reglas aplicables.")

# Función que selecciona la inferencia
def run_inference():
    kb = kb_deportes if db_var.get() == 'deportes' else kb_vehiculos
    if inference_var.get() == 'forward':
        ask_forward_inputs(kb)  # Llamar a la función de forward chaining con entradas del usuario
    else:
        goal = simpledialog.askstring("Objetivo", "¿Qué resultado deseas alcanzar?")
        backward_chaining(kb, goal)

# Interfaz gráfica
root = tk.Tk()
root.title("Sistema Experto")

# Selección de inferencia
ttk.Label(root, text="Selecciona tipo de inferencia:").pack()
inference_var = tk.StringVar(value='forward')
ttk.Radiobutton(root, text="Forward chaining", variable=inference_var, value='forward').pack()
ttk.Radiobutton(root, text="Backward chaining", variable=inference_var, value='backward').pack()

# Selección de base de conocimientos
ttk.Label(root, text="Selecciona base de conocimientos:").pack()
db_var = tk.StringVar(value='deportes')
ttk.Radiobutton(root, text="Deportes", variable=db_var, value='deportes').pack()
ttk.Radiobutton(root, text="Vehículos", variable=db_var, value='vehiculos').pack()

# Botón de inferencia
ttk.Button(root, text="Inferir", command=run_inference).pack()

root.mainloop()
