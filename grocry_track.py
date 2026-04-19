import tkinter as tk
from tkinter import ttk, messagebox
import sqlite3
from datetime import datetime

class GrocyTrack:
    def __init__(self, root):
        self.root = root
        self.root.title("GrocyTrack - Grocery Management System")
        self.root.geometry("1100x700")
        
        # Initialize Database
        self.create_db()
        
        # UI Setup
        self.setup_ui()

    def create_db(self):
        conn = sqlite3.connect("grocytrack.db")
        cursor = conn.cursor()
        cursor.execute('''CREATE TABLE IF NOT EXISTS products 
                          (id INTEGER PRIMARY KEY AUTOINCREMENT, 
                           name TEXT, category TEXT, market_price REAL, 
                           our_price REAL, shelf_stock INTEGER, 
                           storage_stock INTEGER, discount TEXT)''')
        # Add sample data if empty
        cursor.execute("SELECT COUNT(*) FROM products")
        if cursor.fetchone()[0] == 0:
            sample_data = [
                ('Amul Milk', 'Dairy', 30.0, 25.0, 40, 10, '17%'),
                ('Amul Butter', 'Dairy', 60.0, 52.0, 25, 5, '13%'),
                ('T-Shirt', 'Cloth', 500.0, 399.0, 15, 20, '20%')
            ]
            cursor.executemany("INSERT INTO products (name, category, market_price, our_price, shelf_stock, storage_stock, discount) VALUES (?,?,?,?,?,?,?)", sample_data)
        conn.commit()
        conn.close()

    def setup_ui(self):
        # --- Top Bar (Date & Settings) ---
        top_bar = tk.Frame(self.root, bg="#1b4332", height=40)
        top_bar.pack(fill="x")
        
        now = datetime.now()
        date_label = tk.Label(top_bar, text=f"📅 {now.strftime('%d %b, %Y')}  |  🕒 {now.strftime('%H:%M')}", 
                              fg="white", bg="#1b4332", font=("Arial", 10))
        date_label.pack(side="left", padx=20)
        
        btn_settings = tk.Button(top_bar, text="⚙️ Settings", bg="#2d6a4f", fg="white", bd=0, padx=10)
        btn_settings.pack(side="right", padx=20)

        # --- Header ---
        header = tk.Frame(self.root, bg="#2d6a4f", pady=10)
        header.pack(fill="x")
        tk.Label(header, text="GrocyTrack", font=("Arial", 22, "bold"), fg="white", bg="#2d6a4f").pack(side="left", padx=20)
        
        # Navigation
        nav_frame = tk.Frame(header, bg="#2d6a4f")
        nav_frame.pack(side="right", padx=20)
        for text in ["Dashboard", "All Products", "Sales", "Orders"]:
            tk.Button(nav_frame, text=text, bg="#2d6a4f", fg="white", bd=0, font=("Arial", 11)).pack(side="left", padx=10)

        # --- Search & Add Category ---
        search_frame = tk.Frame(self.root, pady=20)
        search_frame.pack(fill="x", padx=40)
        
        self.search_var = tk.StringVar()
        self.search_var.trace("w", lambda *args: self.load_products())
        tk.Entry(search_frame, textvariable=self.search_var, font=("Arial", 14), width=40).pack(side="left")
        tk.Label(search_frame, text="🔍 Search categories or products...", fg="gray").pack(side="left", padx=10)
        
        tk.Button(search_frame, text="+ Add Category", bg="white", fg="#2d6a4f", font=("Arial", 10, "bold"), 
                  highlightthickness=2, highlightbackground="#2d6a4f").pack(side="right")

        # --- Product Table ---
        table_frame = tk.Frame(self.root)
        table_frame.pack(fill="both", expand=True, padx=40)

        columns = ("id", "name", "cat", "m_price", "o_price", "disc", "shelf", "store", "profit")
        self.tree = ttk.Treeview(table_frame, columns=columns, show="headings", height=10)
        
        # Table Headers
        headings = {"id": "#", "name": "Product Name", "cat": "Category", "m_price": "Market Price", 
                    "o_price": "Our Price", "disc": "Discount", "shelf": "Shelf", "store": "Storage", "profit": "Profit"}
        for col, text in headings.items():
            self.tree.heading(col, text=text)
            self.tree.column(col, width=100, anchor="center")

        self.tree.pack(fill="both", expand=True)
        
        # --- Action Buttons ---
        btn_frame = tk.Frame(self.root, pady=20)
        btn_frame.pack()
        
        actions = [("✏️ Edit", "#2d6a4f"), ("🔍 Detail", "#1b4332"), ("📦 Batch", "#0077b6"), ("🗑️ Delete", "#c1121f")]
        for text, color in actions:
            btn = tk.Button(btn_frame, text=text, bg=color, fg="white", font=("Arial", 10, "bold"), width=12, pady=5)
            btn.pack(side="left", padx=10)
            if "Delete" in text:
                btn.config(command=self.delete_product)

        self.load_products()

    def load_products(self):
        # Clear table
        for item in self.tree.get_children():
            self.tree.delete(item)
            
        search_query = self.search_var.get()
        conn = sqlite3.connect("grocytrack.db")
        cursor = conn.cursor()
        
        if search_query:
            cursor.execute("SELECT * FROM products WHERE name LIKE ? OR category LIKE ?", (f'%{search_query}%', f'%{search_query}%'))
        else:
            cursor.execute("SELECT * FROM products")
            
        for row in cursor.fetchall():
            # Calculate Profit
            profit = (row[4] - (row[3] * 0.8)) * row[5] # Simplified logic
            display_row = list(row) + [f"₹{profit:.2f}"]
            self.tree.insert("", "end", values=display_row)
        conn.close()

    def delete_product(self):
        selected = self.tree.selection()
        if not selected:
            messagebox.showwarning("Warning", "Please select a product to delete")
            return
            
        product_id = self.tree.item(selected)['values'][0]
        if messagebox.askyesno("Confirm", "Delete this product?"):
            conn = sqlite3.connect("grocytrack.db")
            conn.execute("DELETE FROM products WHERE id=?", (product_id,))
            conn.commit()
            conn.close()
            self.load_products()

if __name__ == "__main__":
    root = tk.Tk()
    app = GrocyTrack(root)
    root.mainloop()