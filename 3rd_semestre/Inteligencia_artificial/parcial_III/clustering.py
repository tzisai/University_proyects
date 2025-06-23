import pandas as pd
from sklearn.preprocessing import StandardScaler
import random
import numpy as np
import math
import matplotlib.pyplot as plt

# Load the Excel file into a DataFrame
df = pd.read_excel('dataset_2.xlsx')

# Display the first few rows of the DataFrame
print(df.head())

# Handle missing values if any
df.fillna(0, inplace=True)

# Normalize the data (if necessary)
features = df.columns[1:-1]  # Exclude the first column (aminoacid) and last column (element)
scaler = StandardScaler()
df[features] = scaler.fit_transform(df[features])

def initialize_centroids(data, k):
    centroids = data.copy()
    np.random.shuffle(centroids)
    return centroids[:k]

def euclidean_distance(point1, point2):
    return math.sqrt(sum((x - y) ** 2 for x, y in zip(point1, point2)))

def assign_clusters(data, centroids):
    clusters = [[] for _ in range(len(centroids))]
    for point in data:
        distances = [euclidean_distance(point, centroid) for centroid in centroids]
        closest_centroid = distances.index(min(distances))
        clusters[closest_centroid].append(point)
    return clusters

def update_centroids(clusters):
    new_centroids = []
    for cluster in clusters:
        new_centroid = [sum(dimension) / len(cluster) for dimension in zip(*cluster)]
        new_centroids.append(new_centroid)
    return new_centroids

def kmeans(data, k, max_iterations=100):
    centroids = initialize_centroids(data, k)
    for _ in range(max_iterations):
        clusters = assign_clusters(data, centroids)
        new_centroids = update_centroids(clusters)
        if all(np.allclose(c1, c2) for c1, c2 in zip(centroids, new_centroids)):
            break
        centroids = new_centroids
    return centroids, clusters

# Extract features for clustering
data = df[features].values

# Number of clusters
k = 3

# Perform KMeans clustering
centroids, clusters = kmeans(data, k)

print("Centroids:")
for centroid in centroids:
    print(centroid)

print("\nClusters:")
for i, cluster in enumerate(clusters):
    print(f"Cluster {i}:")
    for point in cluster:
        print(point)

# Visualization of the clusters (assuming 2D for visualization purposes)
colors = ['r', 'g', 'b']
for i, cluster in enumerate(clusters):
    for point in cluster:
        plt.scatter(point[0], point[1], color=colors[i])
    plt.scatter(centroids[i][0], centroids[i][1], color=colors[i], marker='x', s=200, linewidths=3)

plt.xlabel('Amino Acid Property 1')
plt.ylabel('Amino Acid Property 2')
plt.title('KMeans Clustering of VIH Virus Data')
plt.show()
