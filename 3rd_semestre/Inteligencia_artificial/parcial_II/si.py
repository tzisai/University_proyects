import tkinter as tk
from tkinter import ttk, PhotoImage, messagebox

# Bases de conocimiento
from KB_deportes import kb_deportes
from KB_vehiculos import kb_vehiculos

# Función de Forward chaining
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

# Función para hacer la pregunta con forward chaining
def ask_forward_inputs(kb):
    preguntas = [
        ("num_jugadores", "¿Cuántos jugadores tiene tu deporte?"),
        ("balon", "¿Se usa un balón? (si/no)"),
        ("tipo_cancha", "¿Qué forma tiene la cancha? (rectangular/diamante)"),
        ("cancha", "¿Cuál es la superficie? (superficie dura/cesped/hielo/arena/mesa)"),
        ("equipo", "¿Se usa algún equipamiento? (si/no)")
    ]
    
    inputs_user = {}

    def siguiente_pregunta(index=0):
        if index < len(preguntas):
            variable, pregunta = preguntas[index]
            label.config(text=pregunta)
            save_button.config(command=lambda: guardar_respuesta(variable, index))
        else:
            deporte = forward_chaining(kb, inputs_user)
            textbox2.config(state="normal")
            textbox2.delete(1.0, tk.END)
            textbox2.insert(tk.END, f"El deporte es: {deporte}")
            textbox2.config(state="disabled")

    def guardar_respuesta(variable, index):
        respuesta = textbox1.get("1.0", tk.END).strip()
        inputs_user[variable] = respuesta
        textbox1.delete("1.0", tk.END)
        siguiente_pregunta(index + 1)

    siguiente_pregunta()

# Función de Backward chaining
def backward_chaining(kb, goal):
    applicable_rules = []
    for rule in kb:
        if rule['then']['value'].lower() == goal.lower():  # Compara el valor en `then`
            applicable_rules.append(rule)
    
    if applicable_rules:
        result = "\n".join([f"Regla {rule['rule_name']}: IF {rule['if']} THEN {rule['then']}" for rule in applicable_rules])
        textbox2.config(state="normal")
        textbox2.delete(1.0, tk.END)
        textbox2.insert(tk.END, result)
        textbox2.config(state="disabled")
    else:
        textbox2.config(state="normal")
        textbox2.delete(1.0, tk.END)
        textbox2.insert(tk.END, "No se encontraron reglas aplicables.")
        textbox2.config(state="disabled")

# Función para preguntar el objetivo para backward chaining
def ask_goal_for_backward(kb):
    label.config(text="¿Qué resultado deseas alcanzar?", wraplength=400)  # Ajuste para más texto
    save_button.config(command=lambda: guardar_goal(kb))

def guardar_goal(kb):
    goal = textbox1.get("1.0", tk.END).strip()
    print(f"Objetivo para backward chaining: {goal}")  # Debug
    textbox1.delete("1.0", tk.END)
    backward_chaining(kb, goal)

# Función que selecciona la inferencia
def run_inference():
    kb = kb_deportes if Combo2.get() == 'Deportes' else kb_vehiculos
    print(f"KB seleccionada: {Combo2.get()}")  # Debug
    if Combo1.get() == 'Forward Chain':
        ask_forward_inputs(kb)
    else:
        ask_goal_for_backward(kb)

# Función para limpiar las cajas de texto y la etiqueta de preguntas
def limpiar_campos():
    label.config(text="Pregunta", wraplength=400)
    textbox1.delete("1.0", tk.END)
    textbox2.config(state="normal")
    textbox2.delete(1.0, tk.END)
    textbox2.config(state="disabled")

# Crear la ventana principal
root = tk.Tk()
root.title("Agente Inteligente")
root.geometry("600x600")
root.config(bg="#2B2B2B")  # Fondo de la ventana

style = ttk.Style()
style.theme_use('clam')

style.configure("TCombobox",
                fieldbackground="#3C3F41",  
                background="#3C3F41",       
                foreground="white",         
                borderwidth=0,              
                selectbackground="#3C3F41", 
                selectforeground="white")

style.map("TCombobox",
          fieldbackground=[('readonly', '#3C3F41')], 
          foreground=[('readonly', 'white')])        

# Etiqueta del título principal
title_label = tk.Label(root, text="Agente Inteligente", font=("Arial", 24), fg="white", bg="#2B2B2B")
title_label.pack(pady=20)

# Frame para los elementos en una fila
frame = tk.Frame(root, bg="#2B2B2B")
frame.pack(pady=20)

vlist1 = ["Forward Chain", "Backward Chain"]
vlist2 = ["Deportes", "Autos"]

Combo1 = ttk.Combobox(frame, values=vlist1, style="TCombobox", state="readonly", font=("Arial", 12))
Combo1.set("Selecciona Interpretador")
Combo1.pack(side=tk.LEFT, padx=5, pady=5)

Combo2 = ttk.Combobox(frame, values=vlist2, style="TCombobox", state="readonly", font=("Arial", 12))
Combo2.set("Selecciona KB")
Combo2.pack(side=tk.LEFT, padx=5, pady=5)

infer_button = tk.Button(frame, text="Inferir", bg="#3C3F41", fg="white", font=("Arial", 10), width=15, height=1, command=run_inference)
infer_button.pack(side=tk.LEFT, padx=5, pady=5)

bottom_frame = tk.Frame(root, bg="#2B2B2B")
bottom_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

img = PhotoImage(file="GY5pQpzWoAAVDST (484×504).png")

img_label = tk.Label(bottom_frame, image=img, bg="#2B2B2B")
img_label.pack(side=tk.LEFT, padx=10)

right_frame = tk.Frame(bottom_frame, bg="#2B2B2B")
right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=10)

upper_frame = tk.Frame(right_frame, bg="#2B2B2B")
upper_frame.pack(fill=tk.X, pady=5)

label = tk.Label(upper_frame, text="", font=("Arial", 12), fg="white", bg="#2B2B2B", wraplength=400)  # wraplength ajusta el texto
label.pack(anchor=tk.W)

textbox1 = tk.Text(upper_frame, font=("Arial", 12), bg="#3C3F41", fg="white", insertbackground="white", height=2)
textbox1.pack(fill=tk.X, pady=5)

# Botones "Guardar Respuesta" y "Limpiar" en la misma fila
button_frame = tk.Frame(upper_frame, bg="#2B2B2B")
button_frame.pack(pady=5)

save_button = tk.Button(button_frame, text="Guardar Respuesta", bg="#3C3F41", fg="white", font=("Arial", 10))
save_button.pack(side=tk.LEFT, padx=5)

limpiar_button = tk.Button(button_frame, text="Limpiar", bg="#3C3F41", fg="white", font=("Arial", 10), command=limpiar_campos)
limpiar_button.pack(side=tk.LEFT, padx=5)

textbox2 = tk.Text(right_frame, font=("Arial", 12), bg="#3C3F41", fg="white", insertbackground="white", state="disabled")
textbox2.pack(fill=tk.BOTH, expand=True, pady=5)

root.mainloop()
