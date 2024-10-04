struct Vertex {
    int x;
    int y;
};

struct Sprite {
    std::vector<Vertex> vertices;
    SDL_Rect boundingBox;
};

void detectVertices(const Uint32* pixels, int width, int height, int threshold, std::vector<Vertex>& vertices) {
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int pixelValue = pixels[y * width + x];
            if (pixelValue > threshold) {
                // Check for edge conditions
                if (pixels[y * width + x - 1] < threshold &&
                    pixels [y * width + x + 1] < threshold &&
                    pixels[(y - 1) * width + x] < threshold &&
                    pixels[(y + 1) * width + x] < threshold) {

                    vertices.push_back({x, y});
                }
            }
        }
    }
}

void calculateBoundingBox(Sprite& sprite) {
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;

    for (const Vertex& vertex : sprite.vertices) {
        minX = std::min(minX, vertex.x);
        minY = std::min(minY, vertex.y);
        maxX = std::max(maxX, vertex.x);
        maxY = std::max(maxY, vertex.y);
    }

    sprite.boundingBox = { minX, minY, maxX - minX, maxY - minY };
}

Uint32* GetPixelData(SDL_Texture* texture) 
{
SDL_Surface* surface = SDL_CreateRGBSurfaceFrom( texture->pixels, texture->width, texture->height, texture->format->BitsPerPixel, texture->pitch, texture->format->Rmask, texture->format->Gmask, texture->format->Bmask, texture->format->Amask );
Uint32* pixels = (Uint32*)surface->pixels;
SDL_FFreeSurface(surface);
return pixels;
}

int CalculateThreshold(Uint32* pixels) {
Uint32 darkestPixel = UINT32_MAX;
for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
        darkestPixel = std::min(darkestPixel, pixels[y * width + x]);
    }
}

int threshold = darkestPixel + 15; // Adjust the offset as needed
}

std::vector<SDL_Point> calculateNormals(const Sprite& sprite) {
    std::vector<SDL_Point> normals;
    for (int i = 0; i < sprite. vertices.size(); ++i) {
        int j = (i + 1) % sprite.vertices.size();
        int dx = sprite.vertices[j].x - sprite.vertices[i].x;
        int dy = sprite.vertices[j].y - sprite.vertices[i].y;
        normals.push_back({-dy, dx}); // Normalize if needed
    }
    return normals;
}

std::vector<int> projectSprite(const Sprite& sprite, const SDL_Point& normal) {
    std::vector<int> projections;
    for (const SDL_Point& vertex : sprite.vertices) {
        projections.push_back(vertex.x * normal.x + vertex.y * normal.y);
    }
    return projections;
}

bool checkOverlap(const std::vector<int>& projections1, const std::vector<int>& projections2) {
    int min1 = INT_MAX, max1 = INT_MIN;
    int min2 = INT_MAX, max2 = INT_MIN;

    for (int projection : projections1) {
        min1 = std::min(min1, projection);
        max1 = std::max(max1, projection);
    }

    for (int projection : projections2) {
        min2 = std::min(min2, projection);
        max2 = std::max(max2, projection);
    }

    return !(max1 < min2 || min1 > max2);
}

bool SATCollision(const sprite& sprite1, const sprite& sprite2) {
    std::vector<SDL_Point> normals1 = calculateNormals(sprite1);
    std::vector<SDL_Point> normals2 = calculateNormals(sprite2);

    for (const SDL_Point& normal : normals1) {
        std::vector<int> projections1 = projectSprite(sprite1, normal);
        std::vector<int> projections2 = projectSprite(sprite2, normal);
        if (!checkOverlap(projections1, projections2)) {
            return false; // No overlap
        }
    }

    for (const SDL_Point& normal : normals2) {
        std::vector<int> projections1 = projectSprite(sprite1, normal);
        std::vector<int> projections2 = projectSprite(Sprite2, normal);
        if (!checkOverlap(projections1, projections2)) {
            return false; // No overlap
        }
    }

    return true; // Overlap found on all axes
}


bool checkCollision(const Sprite& sprite1, const Sprite& sprite2) {
    // Check bounding box intersection first
    if (!SDL_HasIntersection(&sprite1.boundingBox, &sprite2.boundingBox)) {
        return false; // No bounding box overlap
    }

    // Perform SAT collision check if bounding boxes intersect
    return SATCollision(sprite1, sprite2);
}
